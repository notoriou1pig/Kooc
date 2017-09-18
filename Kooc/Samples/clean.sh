#!/bin/sh

count=1

ExceptionFile="Exception"

rm -f $ExceptionFile".c"
rm -f $ExceptionFile".h"

while [ -e "in$count.c" ]
do
    if [ -e "in$count.c" ]
    then
	rm -vf "in$count.c"
    fi
    if [ -e "in$count.h" ]
    then
	rm -vf "in$count.h"
    fi
    if [ -e "in$count.o" ]
    then
	rm -vf "in$count.o"
    fi
    if [ -e "in$count" ]
    then
	rm -vf "in$count"
    fi
    count=$((count+1))
done

if [ -e "sample.log" ]
then
    rm -vf "sample.log"
fi
