#!/bin/sh
#$Id: check_iso.sh.in,v 1.10 2005/09/15 06:36:01 rocky Exp $

if test -z $srcdir ; then
  srcdir=`pwd`
fi

. ${srcdir}/check_common_fn

if test ! -x ../src/iso-info ; then
  exit 77
fi

BASE=`basename $0 .sh`
fname=copying

opts="--quiet ${srcdir}/${fname}.iso --iso9660 "
test_iso_info  "$opts" ${fname}.dump ${srcdir}/${fname}.right
RC=$?
check_result $RC 'iso-info basic test' "$ISO_INFO $opts"

opts="--image ${srcdir}/${fname}.iso --extract $fname "
test_iso_read  "$opts" ${fname} ${srcdir}/../COPYING
RC=$?
check_result $RC 'iso-read basic test' "$ISO_READ $opts"

if test -n "1"; then
  fname=copying-rr
  opts="--quiet ${srcdir}/${fname}.iso --iso9660 "
  test_iso_info  "$opts" ${fname}.dump ${srcdir}/${fname}.right
  RC=$?
  check_result $RC 'iso-info Rock Ridge test' "$ISO_INFO $opts"
fi

if test -n "1" ; then
  BASE=`basename $0 .sh`
  fname=joliet
  opts="--quiet ${srcdir}/${fname}.iso --iso9660 "
  test_iso_info  "$opts" ${fname}-nojoliet.dump ${srcdir}/${fname}.right
  RC=$?
  check_result $RC 'iso-info Joliet test' "$cmdline"
  opts="--quiet ${srcdir}/${fname}.iso --iso9660 --no-joliet "
  test_iso_info  "$opts" ${fname}-nojoliet.dump \
                 ${srcdir}/${fname}-nojoliet.right
  RC=$?
  check_result $RC 'iso-info --no-joliet test' "$cmdline"
fi

exit $RC

#;;; Local Variables: ***
#;;; mode:shell-script ***
#;;; eval: (sh-set-shell "bash") ***
#;;; End: ***
