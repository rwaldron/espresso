#!/usr/bin/env bash

PARTNO=m2560
PROGRAMMER=stk500v2
BAUDRATE=115200

AVRDUDE=`which avrdude`
ARGS="-p $PARTNO -c $PROGRAMMER -b $BAUDRATE -DV"
PORT=

for port in `ls $2 $PORT /dev/tty.usb* 2> /dev/null`; do
	if $AVRDUDE $ARGS -P$port > /dev/null 2>&1; then
		PORT=$port
		break
	fi
done

if [ -z $PORT ]; then
	echo "No Arduino Mega 2560 found"
	exit 1
fi

if [ ${1##*.} == "hex" ]; then
	$AVRDUDE $ARGS -Uflash:w:$1 -P$PORT
	exit
fi

bin=/tmp/$RANDOM.bin
tools/jsc -B$bin $1

$AVRDUDE $ARGS -Ueeprom:w:$bin:r -P$PORT
