#***************************************************************************
#                                  _   _ ____  _
#  Project                     ___| | | |  _ \| |
#                             / __| | | | |_) | |
#                            | (__| |_| |  _ <| |___
#                             \___|\___/|_| \_\_____|
#
# Copyright (C) 1998 - 2005, Daniel Stenberg, <daniel@haxx.se>, et al.
#
# This software is licensed as described in the file COPYING, which
# you should have received as part of this distribution. The terms
# are also available at http://curl.haxx.se/docs/copyright.html.
#
# You may opt to use, copy, modify, merge, publish, distribute and/or sell
# copies of the Software, and permit persons to whom the Software is
# furnished to do so, under the terms of the COPYING file.
#
# This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
# KIND, either express or implied.
#
# $Id: Makefile.dist,v 1.31 2005/03/31 07:02:02 bagder Exp $
###########################################################################

all:
	./configure
	make

ssl:
	./configure --with-ssl
	make

borland:
	cd lib
	make -f Makefile.b32
	cd ..\src
	make -f Makefile.b32

borland-ssl:
	cd lib
	make -f Makefile.b32 WITH_SSL=1
	cd ..\src
	make -f Makefile.b32 WITH_SSL=1

borland-ssl-zlib:
	cd lib
	make -f Makefile.b32 WITH_SSL=1 WITH_ZLIB=1
	cd ..\src
	make -f Makefile.b32 WITH_SSL=1 WITH_ZLIB=1

borland-clean:
	cd lib
	make -f Makefile.b32 clean
	cd ..\src
	make -f Makefile.b32 clean

watcom:
	cd lib
	wmake -f Makefile.Watcom
	cd ..\src
	wmake -f Makefile.Watcom

watcom-clean:
	cd lib
	wmake -f Makefile.Watcom clean
	cd ..\src
	wmake -f Makefile.Watcom clean

mingw32:
	$(MAKE) -C lib -f Makefile.m32 ZLIB=1
	$(MAKE) -C src -f Makefile.m32 ZLIB=1

mingw32-ssl:
	$(MAKE) -C lib -f Makefile.m32 SSL=1 ZLIB=1
	$(MAKE) -C src -f Makefile.m32 SSL=1 ZLIB=1

mingw32-clean:
	$(MAKE) -C lib -f Makefile.m32 clean
	$(MAKE) -C src -f Makefile.m32 clean

vc-clean:
	cd lib
	nmake -f Makefile.vc6 clean
	cd ..\src
	nmake -f Makefile.vc6 clean

vc-all:
	cd lib
	nmake -f Makefile.vc6 cfg=release
	nmake -f Makefile.vc6 cfg=release-ssl
	nmake -f Makefile.vc6 cfg=release-zlib
	nmake -f Makefile.vc6 cfg=release-ssl-zlib
	nmake -f Makefile.vc6 cfg=release-ssl-dll
	nmake -f Makefile.vc6 cfg=release-zlib-dll
	nmake -f Makefile.vc6 cfg=release-ssl-dll-zlib-dll
	nmake -f Makefile.vc6 cfg=release-dll
	nmake -f Makefile.vc6 cfg=release-dll-ssl-dll
	nmake -f Makefile.vc6 cfg=release-dll-zlib-dll
	nmake -f Makefile.vc6 cfg=release-dll-ssl-dll-zlib-dll
	nmake -f Makefile.vc6 cfg=debug
	nmake -f Makefile.vc6 cfg=debug-ssl
	nmake -f Makefile.vc6 cfg=debug-zlib
	nmake -f Makefile.vc6 cfg=debug-ssl-zlib
	nmake -f Makefile.vc6 cfg=debug-ssl-dll
	nmake -f Makefile.vc6 cfg=debug-zlib-dll
	nmake -f Makefile.vc6 cfg=debug-ssl-dll-zlib-dll
	nmake -f Makefile.vc6 cfg=debug-dll
	nmake -f Makefile.vc6 cfg=debug-dll-ssl-dll
	nmake -f Makefile.vc6 cfg=debug-dll-zlib-dll
	nmake -f Makefile.vc6 cfg=debug-dll-ssl-dll-zlib-dll

vc:
	cd lib
	nmake /f Makefile.vc6 cfg=release
	cd ..\src
	nmake /f Makefile.vc6

vc-zlib:
	cd lib
	nmake /f Makefile.vc6 cfg=release-zlib
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-zlib

vc-ssl:
	cd lib
	nmake /f Makefile.vc6 cfg=release-ssl
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-ssl

vc-ssl-zlib:
	cd lib
	nmake /f Makefile.vc6 cfg=release-ssl-zlib
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-ssl-zlib

vc-ssl-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-ssl-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-ssl-dll

vc-dll-ssl-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-dll-ssl-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-dll-ssl-dll

vc-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-dll

vc-dll-zlib-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-dll-zlib-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-dll-zlib-dll

vc-dll-ssl-dll-zlib-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-dll-ssl-dll-zlib-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-dll-ssl-dll-zlib-dll

vc-ssl-dll-zlib-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-ssl-dll-zlib-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-ssl-dll-zlib-dll

vc-zlib-dll:
	cd lib
	nmake /f Makefile.vc6 cfg=release-zlib-dll
	cd ..\src
	nmake /f Makefile.vc6 cfg=release-zlib-dll

vc-sspi:
	cd lib
	nmake /f Makefile.vc6 cfg=release WINDOWS_SSPI=1
	cd ..\src
	nmake /f Makefile.vc6 cfg=release WINDOWS_SSPI=1

djgpp:
	$(MAKE) -C lib -f Makefile.dj
	$(MAKE) -C src -f Makefile.dj

cygwin:
	./configure
	make

cygwin-ssl:
	./configure --with-ssl
	make

amiga:
	cd ./lib && make -f makefile.amiga
	cd ./src && make -f makefile.amiga

netware:
	$(MAKE) -C lib -f Makefile.netware
	$(MAKE) -C src -f Makefile.netware

netware-ssl:
	$(MAKE) -C lib -f Makefile.netware SSL=1
	$(MAKE) -C src -f Makefile.netware SSL=1

netware-clean:
	$(MAKE) -C lib -f Makefile.netware clean
	$(MAKE) -C src -f Makefile.netware clean

unix: all

unix-ssl: ssl

linux: all

linux-ssl: ssl
