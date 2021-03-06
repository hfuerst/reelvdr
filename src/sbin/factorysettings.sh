#!/bin/sh
#
# resets reelbox to factory settings or prepares the master
# V 1.0 2009-02-19 by Rollercoaster
#

#set -x

VDRDIR=/etc/vdr
SYSCONFIGDIR=/etc/default

# include language
. /etc/default/globals

CleanDpkgs () {
	echo "Lösche Paket-cache (dpkgs)"
	aptitude clean
	aptitude autoclean
}

ClearTimers () {
	echo "Lösche Timer/Suchtimer"
	:> $VDRDIR/timers.conf
	:> $VDRDIR/plugins/epgsearch/epgsearch.conf
	:> $VDRDIR/plugins/epgsearch/epgsearchdone.conf
	:> $VDRDIR/plugins/epgsearch/timersdone.conf
}

DelRecordings () {
	echo "Lösche Aufnahmen"
	echo "WARNING: All recordings/videos/music etc. will now be deleted. Press <ctrl>+c to cancel."
	echo "You have been warned"'!'
	echo "Press Enter to continue"
	read bla
	#for i in music pictures recordings video ; do
	for i in recordings ; do
		rm -rf /media/hd/$i
		mkdir /media/hd/$i
	done
}

ResetSshKeys () {
	rm -f /etc/ssh/ssh_host_dsa_key*
	rm -f /etc/ssh/ssh_host_rsa_key*
	rm -f /usr/NX/home/nx/.ssh/known_hosts
	dpkg-reconfigure nxserver
}

ClearFavorites () {
	echo "Lösche Favoritenliste"
	rm -f $VDRDIR/plugins/reelchannellist/favourites.conf
}

ClearHistory () {
	echo "Lösche History von root + reel"
	rm -f /root/.ssh/*
	rm -f /root/.mc/history
	rm -f /root/.bash_history

	rm -f /home/reel/.ssh/*
	rm -f /home/reel/.mc/history
	rm -f /home/reel/.bash_history
}

ClearLog () {
	echo "Lösche Logs"
	rm -f /var/tmp/epg.data
	rm -rf /var/tmp/*
	rm -f /var/crash/*
	rm -f /var/backups/*
	rm -f /var/log/*
	rm -f /var/log/*/*
}

ResetToEnglish () {
	echo "Stelle Englisch ein"
	sed -i s/"OSDLanguage =.*"/"OSDLanguage = en_US"/ $VDRDIR/setup.conf
	sed -i s/"AudioLanguages =.*"/"AudioLanguages = eng"/ $VDRDIR/setup.conf
	sed -i s/"EPGLanguages =.*"/"EPGLanguages = eng"/ $VDRDIR/setup.conf
}

InstallWizard () {
	echo "Schalte Install-Assist ein"
	sed -i s/"install.stepdone =.*"/"install.stepdone = 0"/ $VDRDIR/setup.conf
}

ResetChannels () {
	echo "Installiere leere Kanalliste"
	cp -a /etc/vdr/channels/New.conf /etc/vdr/channels.conf
	cp -a /etc/default/mcli.factory /etc/default/mcli
}

ResetConfigs () {
	echo "Installiere default-Konfigurationen"
	cp -a /etc/vdr/setup.conf.factory /etc/vdr/setup.conf
	cp -a /etc/default/sysconfig.factory /etc/default/sysconfig
	if RbIce ; then
	    sed -i /DS_ENABLE.*/aETH0=\"yes\"\\nETH0_USE_DHCP=\"yes\" /etc/default/sysconfig
	    sed -i /"ETH1.*"/d /etc/default/sysconfig
	fi
	killall -9 vdr
	:> $VDRDIR/plugins/xinemediaplayer/last_played.playlist
	rm -f $VDRDIR/plugins/reelchannellist/favourites.conf
}

ResetNetworkMini () {
	echo "Installiere Standard Netzwerkeinstellungen"
	cat << EOF > /etc/network/interfaces
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).
#
# WARNING: This file is auto-generated by the ReelBox setup, so you
#          should not edit it manually. Use the setup menu instead.
#
# The loopback network interface
auto lo
iface lo inet loopback
address 127.0.0.1
netmask 255.0.0.0

auto eth0
iface eth0 inet dhcp
EOF

	rm -r /var/lib/dhcp3/*
	:>/etc/resolv.conf
}


NetworkSettings () {
	cat << EOF > /etc/network/interfaces
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).
#
# WARNING: This file is auto-generated by the ReelBox setup, so you
#          should not edit it manually. Use the setup menu instead.
#
# The loopback network interface
auto lo
iface lo inet loopback
address 127.0.0.1
netmask 255.0.0.0

auto eth0
iface eth0 inet manual
up ifconfig eth0 up

auto eth1
iface eth1 inet dhcp
EOF
	:>/etc/resolv.conf
	rm -r /var/lib/dhcp3/*
}

SetPermissions () {
	echo "Setting permissions for /media/hd"
	for i in music pictures recordings video ; do
		chgrp -R ftpusers /media/hd/$i
		chmod -R g+w,g+w /media/hd/$i
	done
}

SwitchToStable() {
	echo "Stelle Paketverwaltung auf 'stable'"
	aptitude install -y reelbox-stable
}

### main
case $1 in
	--preparemaster)
		SwitchToStable
		CleanDpkgs
		ResetSshKeys
		ClearHistory
		ClearLog
		ClearTimers
		ClearFavorites
		ResetToEnglish
		InstallWizard
		ResetChannels
		ResetConfigs
		NetworkSettings
		DelRecordings
		SetPermissions
		;;
	--factory)
		SwitchToStable
		CleanDpkgs
		ClearHistory
		ClearLog
		ClearTimers
		ResetToEnglish
		InstallWizard
		ResetChannels
		ResetConfigs
		NetworkSettings
		setup-net restart
		SetPermissions
		;;
	--netclient)
		SwitchToStable
		CleanDpkgs
		ClearHistory
		ClearLog
		ClearTimers
		ClearFavorites
		ResetConfigs
		ResetChannels
		ResetNetworkMini
		;;
	*)
		echo "You should not call this script directly. It is for use from the reelbox software only."
		;;
esac
