#
# Makefile for a Video Disk Recorder plugin
#
# $Id$

# The official name of this plugin.
# This name will be used in the '-P...' option of VDR to load the plugin.
# By default the main source file also carries this name.
#
PLUGIN = radio

### The object files (add further files here):
OBJS = $(PLUGIN).o radioaudio.o radioskin.o radiotools.o radioepg.o inforx.o

### The directory environment:
VDRDIR = ../../..
LIBDIR = ../../lib
TMPDIR = /tmp

### Allow user defined options to overwrite defaults:
-include $(VDRDIR)/Make.config
-include $(VDRDIR)/Make.common
