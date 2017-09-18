#!/usr/bin/env bash

count="$1"
if [ "$count" = "" ]; then
  count=1
fi
NFAILED=0

ExceptionFile="./Exception"

echo -n > sample.log

while [ -e "in$count.kc" ]
do
    FAILED=0
    REASON=""
    echo -n "Test $count : "
    head -n 1 "in$count.kc" | grep -E '^//' &> /dev/null
    if [ "$?" = "0" ]; then
      SUBJECT=`head -n 1 "in$count.kc" | sed 's/^\/\/ //'`
      echo -n "$SUBJECT "
    fi
    echo "in$count.kc" >> sample.log
    echo -n '...'
    ../kooc "in$count.kc" &>> sample.log
    if [ "$?" != "0" ]; then
      FAILED=1
      REASON="compiling in$count.kc"
    fi
    diff "in$count.c" "out$count.c" &>> sample.log
    if [ "$?" != "0" ]; then
      FAILED=1
      REASON="diff in$count.kc"
    fi
    if [ -e "in$count.kh" ]
    then
	echo "in$count.kh" >> sample.log
	../kooc "in$count.kh" &>> sample.log
        if [ "$?" != "0" ]; then
          FAILED=1
          REASON="compiling in$count.kh"
        fi
	diff "in$count.h" "out$count.h" &>> sample.log
        if [ "$?" != "0" ]; then
          FAILED=1
          REASON="diff in$count.kh"
        fi
    fi
    ../kooc $ExceptionFile".kc" 1>> /dev/null 2>> /dev/null
    ../kooc $ExceptionFile".kh" 1>> /dev/null 2>> /dev/null
    echo "Compiling in$count.c" >> sample.log
    gcc "in$count.c" $ExceptionFile".c" -o "in$count" &>> sample.log
    if [ "$?" != "0" ]; then
      FAILED=1
      REASON="gcc in$count.c"
    else
      echo "executing ./in$count" >> sample.log
      "./in$count" &>> sample.log
      if [ "$?" != "0" ]; then
        FAILED=1
        REASON="executing ./in$count"
      fi
    fi
    if [ "$FAILED" = "1" ]; then
      let NFAILED=NFAILED+1
      echo -e " \033[31mFAILED $REASON\033[0m"
    else
      echo -e " \033[32mPASSED\033[0m"
    fi
    count=$((count+1))
done

exit $NFAILED

