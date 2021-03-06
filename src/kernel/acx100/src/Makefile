ifndef ACX_DEBUG
  ACX_DEBUG=1
  $(warning ACX_DEBUG was not defined, assuming 1)
endif # ACX_DEBUG

ifndef ACX_IO_WIDTH
  ACX_IO_WIDTH=16
  $(warning ACX_IO_WIDTH was not defined, assuming 16bit access)
endif # ACX_DEBUG

PWD=$(shell pwd)
KERNELRELEASE=$(shell uname -r)
KERNELDIR = /lib/modules/$(KERNELRELEASE)
MODULE_PATH = net
INSTALL = /usr/bin/install -c
# work around issues with sudo users lacking /sbin in their path
DEPMOD = $(shell test -f /sbin/depmod && echo /sbin/depmod || which depmod)
LN = $(shell which ln)
# driver flags common to all kernel versions and configurations
#COMMON_COMPILE_FLAGS = -msoft-float -pedantic -Wwrite-strings -Wmissing-declarations
COMMON_COMPILE_FLAGS = -msoft-float
#COMMON_DRIVER_DEFINES = -DACX_DEBUG=$(ACX_DEBUG) -DACX_IO_WIDTH=$(ACX_IO_WIDTH) -DPOWER_SAVE_80211=1
COMMON_DRIVER_DEFINES = -DACX_DEBUG=$(ACX_DEBUG) -DACX_IO_WIDTH=$(ACX_IO_WIDTH)

export CPPFLAGS += $(COMMON_DRIVER_DEFINES)

-include $(KERNELDIR)/build/.config

.PHONY: depmod all clean install uninstall

# File naming style:
# Driver modules should be named acx_HARDWARE.(k)o
# Other files should be named acx_HARDWARE_FUNCTION.o
# acx100 specific files should be named acx100_XXX
# Renaming can happen gradually over time.
pci_objs = acx100.o acx100_conv.o acx100_helper.o acx100_helper2.o acx100_ioctl.o acx80211frm.o idma.o ihw.o ioregister.o

usb_objs = acx_usb_80211frm.o acx_usb_conv.o acx_usb_helper.o acx_usb_helper2.o acx_usb_idma.o acx_usb_ihw.o acx_usb_ioctl.o acx_usb_main.o 

ifeq ($(PATCHLEVEL),) # PATCHLEVEL only set if acting as "kbuild 2.6 makefile"

-include $(ACX100_SRC)../config.mk

USBCFLAGS =

ifdef CONFIG_MODVERSIONS
CPPFLAGS += -DMODVERSIONS -include $(KERNEL_BUILD)/include/linux/modversions.h
USBCFLAGS += -DMODVERSIONS -include $(KERNEL_BUILD)/include/linux/modversions.h
endif

# 2.6 in-tree (kbuild)
ifdef KERN26
MODULES = acx_pci.ko acx_usb.ko
CLEAN_EXTRA = *.mod *.mod.c *.mod.o *.o .*.cmd acx_usb*.c

ifeq ($(KERNEL_BUILD),$(KERNEL_OUTPUT))
TMPOUT =
else # ifeq KERNEL_BUILD...
TMPOUT = O=$(PWD)/tmp # need to use a temporary output dir
endif # ifeq KERNEL_BUILD...

modules:
	if test -n $(TMPOUT); then \
	mkdir -p $(PWD)/tmp; \
	cp $(KERNEL_OUTPUT)/.config $(PWD)/tmp; \
	fi
	# use "make V=1" to see full compile execution
	make -C $(KERNEL_BUILD) SUBDIRS=$(PWD) $(TMPOUT) \
		MODVERDIR=$(PWD) WLAN_HOSTIF=WLAN_PCI modules
	# ugh, very bloody hack, but I don't know how to make
	# the Makefile accept the different filenames USB uses. Anyone?
	if test -n "$(ACX100_SRC)"; then \
	cd $(ACX100_SRC); \
	fi
	$(LN) -f -s acx80211frm.c acx_usb_80211frm.c
	$(LN) -f -s acx100_conv.c acx_usb_conv.c
	$(LN) -f -s acx100_helper.c acx_usb_helper.c
	$(LN) -f -s acx100_helper2.c acx_usb_helper2.c
	$(LN) -f -s idma.c acx_usb_idma.c
	$(LN) -f -s ihw.c acx_usb_ihw.c
	$(LN) -f -s acx100_ioctl.c acx_usb_ioctl.c
	$(LN) -f -s acx100_usb.c acx_usb_main.c
	if test -n "$(ACX100_SRC)"; then \
	cd -; \
	fi
	make -C $(KERNEL_BUILD) SUBDIRS=$(PWD) $(TMPOUT) \
		MODVERDIR=$(PWD) WLAN_HOSTIF=WLAN_USB modules
	@echo
	@echo "**************************"
	@echo "Compilation finished."
	@echo "Make sure to copy required firmware files to /usr/share/acx/ or where your hotplug"
	@echo "scripts expect (default /lib/firmware/) before proceeding!" 
	@echo "**************************"

all: modules

install: all
else # KERN26
MODULES = "acx_pci.o acx_usb.o"
CLEAN_EXTRA = *.o acx_usb*.c

# 2.4 out-of-tree
include $(ACX100_SRC)../config.mk

CPPFLAGS += -D__KERNEL__ -DMODULE -DWLAN_HOSTIF=WLAN_PCI -I$(KERNEL_BUILD)/include -I../include
LDFLAGS = -m elf_i386 -r
CC = gcc
USBCFLAGS += -D__KERNEL__ -I$(KERNEL_BUILD)/include  -Wall -Wstrict-prototypes  -Wno-trigraphs  -O -fno-strict-aliasing -fno-common -fomit-frame-pointer -pipe -mpreferred-stack-boundary=4 -march=i586 -DMODULE -I../include/ -c -DWLAN_HOSTIF=WLAN_USB $(COMMON_DRIVER_DEFINES)
CFLAGS += -Wall -Wstrict-prototypes -Wno-trigraphs -O -fno-strict-aliasing -fno-common -fomit-frame-pointer -pipe -mpreferred-stack-boundary=4 -march=i586
#CPPFLAGS += -D__KERNEL__ -DMODULE -DMODVERSIONS -DWLAN_HOSTIF=WLAN_PCI -I$(KERNEL_BUILD)/include -I../include -include $(KERNEL_BUILD)/include/linux/modversions.h

includes = $(wildcard ../include/*.h)

# File naming style:
# Driver modules should be named acx_HARDWARE.(k)o
# Other files should be named acx_HARDWARE_FUNCTION.o
# acx100 specific files should be named acx100_XXX
# Renaming can happen gradually over time.
objects = acx100.o acx100_ioctl.o acx100_helper.o acx100_helper2.o ihw.o idma.o acx100_conv.o acx80211frm.o ioregister.o

usb_objs = acx_usb_main.o acx_usb_ihw.o acx_usb_helper.o acx_usb_ioctl.o acx_usb_helper2.o acx_usb_80211frm.o acx_usb_idma.o acx_usb_conv.o 

all: acx_pci.o acx_usb.o
	@echo
	@echo "**************************"
	@echo "Compilation finished."
	@echo "Make sure to copy required firmware files to /usr/share/acx/ or where your hotplug"
	@echo "scripts expect (default /lib/firmware/) before proceeding!" 
	@echo "**************************"

acx_pci.o: $(pci_objs)
	$(LD) $(LDFLAGS) -o $@ $^

acx_usb.o: $(usb_objs)
	ld $(LDFLAGS) -o $@ $^

acx_usb_80211frm.o: acx80211frm.c
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_conv.o: acx100_conv.c Makefile
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_helper.o: acx100_helper.c Makefile
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_helper2.o: acx100_helper2.c Makefile
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_ioctl.o: acx100_ioctl.c Makefile
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_idma.o: idma.c
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_ihw.o: ihw.c Makefile
	$(CC) $(USBCFLAGS) -c -o $@ $<

acx_usb_main.o: acx100_usb.c
	$(CC) $(USBCFLAGS) -c -o $@ $<

$(pci_objs): $(includes)

$(usb_objs): $(includes)

endif # KERN26

clean:
	rm -f $(pci_objs) $(usb_objs) ${MODULES} ${CLEAN_EXTRA}

distclean: clean
	rm -f *~ ../doc/*~ ../include/*~ ../scripts/*~ *.rej .#*

install:
	@echo "*** Copying driver modules ${MODULES} to ${KERNELDIR}/${MODULE_PATH}... ***"
	test -d ${KERNELDIR}/${MODULE_PATH} || mkdir ${KERNELDIR}/${MODULE_PATH}
	for mod in ${MODULES}; do \
	  ${INSTALL} $$mod ${KERNELDIR}/${MODULE_PATH}; \
	done
	${DEPMOD} -ae

uninstall:
	for mod in ${MODULES}; do \
	  ${RM} ${KERNELDIR}/${MODULE_PATH}/$$mod; \
	done
	${DEPMOD} -ae

# 2.6 in-tree (kbuild)
else # ifeq PATCHLEVEL

EXTRA_CFLAGS += -I$(src)/../include -DWLAN_HOSTIF=$(WLAN_HOSTIF) $(COMMON_COMPILE_FLAGS) $(COMMON_DRIVER_DEFINES)
#EXTRA_CFLAGS += -Idrivers/net/wireless/acx100 -DWLAN_HOSTIF=$(WLAN_HOSTIF)

ifeq ($(WLAN_HOSTIF),WLAN_PCI)

obj-m += acx_pci.o
acx_pci-objs = $(pci_objs)

else

obj-m += acx_usb.o
acx_usb-objs := $(usb_objs)

endif


endif # ifeq PATCHLEVEL
