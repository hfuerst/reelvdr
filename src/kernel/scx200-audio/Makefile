CC ?= gcc
LD ?= ld
KERNEL_SRC=../kernel-2.6.11.11

# Grab the kernel version right out of the tree
KERNEL_VERSION = $(shell sed -ne 's/"//g;s/^\#define UTS_RELEASE //p' \
                   $(KERNEL_SRC)/include/linux/version.h)

# This is borrowed from the Orinoco drivers.  Thanks fellas...
OLDMAKE = $(filter 2.4%, $(KERNEL_VERSION))

DOT_CONFIG = $(wildcard $(KERNEL_SRC)/.config)
ifeq (,$(DOT_CONFIG))

$(error The kernel source is not configured)
endif
include $(DOT_CONFIG)

CURDIR=$(shell pwd)

ifeq (,$(OLDMAKE))

MODULES=snd-geode.o
snd-geode-objs := amd_geode.o  os_inc.o
obj-m += snd-geode.o


all: modules

modules:
	$(MAKE) -C $(KERNEL_SRC) M=$(CURDIR) modules


install: modules
	install -d $(DESTDIR)/lib/modules/$(KERNEL_VERSION)/kernel/drivers/misc
	install -m 0644 $(MODULES:%.o=%.ko) $(DESTDIR)/lib/modules/$(KERNEL_VERSION)/kernel/drivers/misc

clean:
	rm -f *.o *.ko *.mod.c .*.cmd

else

MODULES=snd-geode.o
KERNEL_HEADERS = -I$(KERNEL_SRC)/include
CPPFLAGS = -D__KERNEL__ -DMODULE -I. $(KERNEL_HEADERS)
CFLAGS=-O2 -g -Wall -Wstrict-prototypes -fno-strict-aliasing -fno-common -pipe

ifdef CONFIG_MODVERSIONS
MFLAG = -DMODVERSIONS -include $(KERNEL_SRC)/include/linux/modversions.h
endif

SRCS=amd_geode.c os_inc.c

all: $(MODULES)

clean:
	@ rm -f *.o  *.ko *.mod.c .*.cmd

install: $(MODULES)
	@ install -d $(DESTDIR)/lib/modules/$(KERNEL_VERSION)/kernel/drivers/misc
	@ install -m 0644 $(MODULES) $(DESTDIR)/lib/modules/$(KERNEL_VERSION)/kernel/drivers/misc/snd-geode.o

snd-geode.o: amd_geode.o os_inc.o
	$(LD) -r -o $@ amd_geode.o os_inc.o

%.o: %.c
	$(CC) -MD $(CFLAGS) $(CPPFLAGS) $(MFLAG) -c $< 

%.s: %.c
	$(CC) -MD $(CFLAGS) $(CPPFLAGS) -S $<
%.i: %.c
	$(CC) -MD $(CPPFLAGS) -E $< -o $@

-include $(SRCS:%.c=%.d)
endif

distclean: clean
	@ rm Makefile clean
