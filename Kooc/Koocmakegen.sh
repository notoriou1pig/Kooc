#!/usr/bin/env bash

basedir=$(dirname $0)

name="$1"

if [[ "$name" = "" ]]; then
  (
    echo "Error : Usage : $0 <project name>"
    echo
  ) > /dev/stderr
  exit 1
fi

srcs="$(find . -name '*.kc' -or -name '*.kh')"

final_srcs=""

for line in $srcs; do
  if [[ "$final_srcs" == "" ]]; then
    final_srcs=$'\t\t'"$line"
  else
    final_srcs="$final_srcs "$'\\\n\t\t'"$line"
  fi
done

export __NAME__="$name"
export __SRCS__="$final_srcs"
export __KOOC__="$basedir/kooc"

envsubst < "$basedir/Makefile.template" > Makefile

