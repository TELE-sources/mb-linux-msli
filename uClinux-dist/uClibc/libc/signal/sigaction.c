/* Copyright (C) 1997-2000,2002,2003,2005,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <features.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

#include <sys/param.h>
#include <sys/syscall.h>

/* Experimentally off - libc_hidden_proto(memcpy) */

/* The difference here is that the sigaction structure used in the
   kernel is not the same as we use in the libc.  Therefore we must
   translate it here.  */
#include <bits/kernel_sigaction.h>

#ifndef LIBC_SIGACTION
extern __typeof(sigaction) __libc_sigaction;
#endif

#if defined __NR_rt_sigaction

/* If ACT is not NULL, change the action for SIG to *ACT.
   If OACT is not NULL, put the old action for SIG in *OACT.  */
int
__libc_sigaction (int sig, const struct sigaction *act, struct sigaction *oact)
{
	int result;
	struct kernel_sigaction kact, koact;

	if (act) {
		memset(&kact, 0, sizeof(kact));
		kact.k_sa_handler = act->sa_handler;
		memcpy (&kact.sa_mask, &act->sa_mask, 
		        MIN(sizeof(kact.sa_mask), sizeof(act->sa_mask)));
		kact.sa_flags = act->sa_flags;
# ifdef HAVE_SA_RESTORER
		kact.sa_restorer = act->sa_restorer;
# endif
	}

	/* XXX The size argument hopefully will have to be changed to the
	   real size of the user-level sigset_t.  */
	result = __syscall_rt_sigaction(sig,
			       act ? __ptrvalue (&kact) : NULL,
			       oact ? __ptrvalue (&koact) : NULL, sizeof(kact.sa_mask));

	if (oact && result >= 0) {
		oact->sa_handler = koact.k_sa_handler;
		memset(&oact->sa_mask, 0, sizeof(oact->sa_mask));
		memcpy (&oact->sa_mask, &koact.sa_mask, 
		        MIN(sizeof(koact.sa_mask), sizeof(oact->sa_mask)));
		oact->sa_flags = koact.sa_flags;
# ifdef HAVE_SA_RESTORER
		oact->sa_restorer = koact.sa_restorer;
# endif
	}

	return result;
}

#else

/* If ACT is not NULL, change the action for SIG to *ACT.
   If OACT is not NULL, put the old action for SIG in *OACT.  */
int
__libc_sigaction (int sig, const struct sigaction *act, struct sigaction *oact)
{
	int result;
	struct old_kernel_sigaction kact, koact;

	if (act) {
		kact.k_sa_handler = act->sa_handler;
		kact.sa_mask = act->sa_mask.__val[0];
		kact.sa_flags = act->sa_flags;
# ifdef HAVE_SA_RESTORER
		kact.sa_restorer = act->sa_restorer;
# endif
	}

	result = __syscall_sigaction(sig,
			       act ? __ptrvalue (&kact) : NULL,
			       oact ? __ptrvalue (&koact) : NULL);

	if (oact && result >= 0) {
		oact->sa_handler = koact.k_sa_handler;
		oact->sa_mask.__val[0] = koact.sa_mask;
		oact->sa_flags = koact.sa_flags;
# ifdef HAVE_SA_RESTORER
		oact->sa_restorer = koact.sa_restorer;
# endif
	}

	return result;
}

#endif

#ifndef LIBC_SIGACTION
libc_hidden_proto(sigaction)
weak_alias(__libc_sigaction,sigaction)
libc_hidden_weak(sigaction)
#endif
