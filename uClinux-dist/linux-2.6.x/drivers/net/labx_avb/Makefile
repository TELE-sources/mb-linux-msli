#
# Makefile for the Lab X Technologies AVB packet engine device drivers
#

# Include Xilinx common definitions
EXTRA_CFLAGS += -I$(TOPDIR)/drivers/xilinx_common

obj-$(CONFIG_LABX_AUDIO_PACKETIZER)       += labx_audio_packetizer.o
obj-$(CONFIG_LABX_AUDIO_DEPACKETIZER)     += labx_audio_depacketizer_.o
obj-$(CONFIG_LABX_REDUNDANCY_SWITCH)      += labx_redundancy_switch.o
obj-$(CONFIG_LABX_AUDIO_TDM)              += labx_tdm_audio.o
obj-$(CONFIG_LABX_AUDIO_TDM_ANALYZER)     += labx_tdm_analyzer.o
obj-$(CONFIG_LABX_LEGACY_BRIDGE)          += labx_legacy_bridge.o

labx_audio_depacketizer_-objs = labx_audio_depacketizer.o
labx_audio_depacketizer_-objs+= labx_audio_depacketizer_netlink.o

# Use this if we need any AVB routines which are common to both drivers; the
# labx_avb-objs target further down implicitly defines a composite object file
# named "labx_avb.o".
# obj-$(CONFIG_LABX_AVB) += labx_avb.o

# Declare multi-part drivers.

# labx_avb-objs	:= foo.o bar.o
