#
# Makefile for a Video Disk Recorder plugin
#
# $Id$

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = remote

# optional components
DEFINES += -DREMOTE_FEATURE_LIRC
DEFINES += -DREMOTE_FEATURE_TCPIP

### The object files (add further files here):

OBJS = $(PLUGIN).o ttystatus.o
ifneq (, $(findstring REMOTE_FEATURE_TCPIP, $(DEFINES)))
OBJS += remotetcp.o
endif

### The directory environment:

VDRDIR = ../../..
LIBDIR = ../../lib
TMPDIR = /tmp

### Allow user defined options to overwrite defaults:

-include $(VDRDIR)/Make.config
-include $(VDRDIR)/Make.common

