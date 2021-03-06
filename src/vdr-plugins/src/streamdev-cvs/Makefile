#
# Makefile for a Video Disk Recorder plugin
#
# $Id: Makefile,v 1.20 2009/11/04 11:12:20 schmirl Exp $

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = streamdev

### The version number of this plugin (taken from the main source file):

VERSION = $(shell grep 'const char \*VERSION *=' common.c | awk '{ print $$5 }' | sed -e 's/[";]//g')

### The C++ compiler and options:

CXX      ?= g++
CXXFLAGS ?= -fPIC -g -O2 -Wall -Woverloaded-virtual -Wno-parentheses

### The directory environment:

VDRDIR = ../../..
LIBDIR = ../../lib
TMPDIR = /tmp

### Allow user defined options to overwrite defaults:

-include $(VDRDIR)/Make.config

### The version number of VDR (taken from VDR's "config.h"):

APIVERSION = $(shell grep 'define APIVERSION ' $(VDRDIR)/config.h | awk '{ print $$3 }' | sed -e 's/"//g')
APIVERSNUM = $(shell grep 'define APIVERSNUM ' $(VDRDIR)/config.h | awk '{ print $$3 }' | sed -e 's/"//g')

### The name of the distribution archive:

ARCHIVE = $(PLUGIN)-$(VERSION)
PACKAGE = vdr-$(ARCHIVE)

### Includes and Defines (add further entries here):

INCLUDES += -I$(VDRDIR)/include -I.

DEFINES += -D_GNU_SOURCE -DPLUGIN_NAME_I18N='"$(PLUGIN)"'

ifeq ($(shell test $(APIVERSNUM) -ge 10704; echo $$?),0)
	DEFINES += -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE
endif

ifdef RBLITE
DEFINES += -DRBLITE
endif

### The object files (add further files here):

COMMONOBJS = common.o \
	\
	tools/source.o tools/select.o tools/socket.o tools/tools.o

CLIENTOBJS = $(PLUGIN)-client.o \
	\
	client/socket.o client/device.o client/setup.o \
	client/filter.o


SERVEROBJS = $(PLUGIN)-server.o \
	\
	server/server.o server/connectionVTP.o server/connectionHTTP.o \
	server/componentHTTP.o server/componentVTP.o server/connection.o \
	server/connectionIGMP.o server/componentIGMP.o server/suspend.o \
	server/menuHTTP.o server/recplayer.o remux/ts2pes.o \
	server/component.o server/suspend.o server/setup.o server/streamer.o \
	server/livestreamer.o server/livefilter.o \
	\
	remux/tsremux.o remux/ts2ps.o remux/ts2es.o remux/extern.o

ifdef DEBUG
	DEFINES += -DDEBUG
endif

### The main target:


### Targets:
plug: libvdr-$(PLUGIN)-client.so libvdr-$(PLUGIN)-server.so

all: plug i18n


libdvbmpeg/libdvbmpegtools.a: libdvbmpeg/*.c libdvbmpeg/*.h
	make -C ./libdvbmpeg libdvbmpegtools.a

### Implicit rules:

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $(DEFINES) $(INCLUDES) -o $@ $<

# Dependencies:

MAKEDEP = $(CXX) -MM -MG
DEPFILE = .dependencies
ifdef GCC3
$(DEPFILE): Makefile
	@rm -f $@
	@for i in $(CLIENTOBJS:%.o=%.c) $(SERVEROBJS:%.o=%.c) $(COMMONOBJS:%.o=%.c) ; do \
		$(MAKEDEP) $(DEFINES) $(INCLUDES) -MT "`dirname $$i`/`basename $$i .c`.o" $$i >>$@ ; \
	done
else
$(DEPFILE): Makefile
	@$(MAKEDEP) $(DEFINES) $(INCLUDES) $(CLIENTOBJS:%.o=%.c) $(SERVEROBJS:%.o=%.c) \
			$(COMMONOBJS:%.o=%.c) > $@
endif

-include $(DEPFILE)

### Internationalization (I18N):

PODIR     = po
LOCALEDIR = $(VDRDIR)/locale
I18Npo    = $(wildcard $(PODIR)/*.po)
I18Nmsgs1  = $(addprefix $(LOCALEDIR)/, $(addsuffix /LC_MESSAGES/vdr-$(PLUGIN)-client.mo, $(notdir $(foreach file, $(I18Npo), $(basename $(file))))))
I18Nmsgs2  = $(addprefix $(LOCALEDIR)/, $(addsuffix /LC_MESSAGES/vdr-$(PLUGIN)-server.mo, $(notdir $(foreach file, $(I18Npo), $(basename $(file))))))
I18Npot   = $(PODIR)/$(PLUGIN).pot

%.mo: %.po
	msgfmt -c -o $@ $<

$(I18Npot): $(wildcard *.c server/*.c client/*.c remux/*.c libdvbmpeg/*.c)
	xgettext -C -cTRANSLATORS --no-wrap --no-location -k -ktr -ktrNOOP --msgid-bugs-address='<reelbox-devel@mailings.reelbox.org>' -o $@ $^

#%.po: $(I18Npot)
%.po:
	msgmerge -U --no-wrap --no-location --backup=none -q $@ $<
	@touch $@

$(I18Nmsgs1): $(LOCALEDIR)/%/LC_MESSAGES/vdr-$(PLUGIN)-client.mo: $(PODIR)/%.mo
	@mkdir -p $(dir $@)
	cp $< $@

$(I18Nmsgs2): $(LOCALEDIR)/%/LC_MESSAGES/vdr-$(PLUGIN)-server.mo: $(PODIR)/%.mo
	@mkdir -p $(dir $@)
	cp $< $@


### i18n Targets:
.PHONY: i18n
i18n: $(I18Npot) $(I18Nmsgs1) $(I18Nmsgs2)

.PHONY: i18n-dist
i18n-dist: $(I18Nmsgs1) $(I18Nmsgs2)

all: libvdr-$(PLUGIN)-client.so libvdr-$(PLUGIN)-server.so i18n

libvdr-$(PLUGIN)-client.so: $(CLIENTOBJS) $(COMMONOBJS) libdvbmpeg/libdvbmpegtools.a
libvdr-$(PLUGIN)-server.so: $(SERVEROBJS) $(COMMONOBJS) libdvbmpeg/libdvbmpegtools.a

%.so:
	$(CXX) $(CXXFLAGS) -shared $^ -o $@
	@cp $@ $(LIBDIR)/$@.$(APIVERSION)

dist: clean
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@mkdir $(TMPDIR)/$(ARCHIVE)
	@cp -a * $(TMPDIR)/$(ARCHIVE)
	@tar czf $(PACKAGE).tgz --exclude CVS -C $(TMPDIR) $(ARCHIVE)
	@-rm -rf $(TMPDIR)/$(ARCHIVE)
	@echo Distribution package created as $(PACKAGE).tgz

clean:
	@-rm -f $(COMMONOBJS) $(CLIENTOBJS) $(SERVEROBJS) $(DEPFILE) $(PODIR)/*.mo $(PODIR)/*.pot *.so *.tgz core* *~
	$(MAKE) -C ./libdvbmpeg clean
