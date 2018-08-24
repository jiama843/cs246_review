#!/bin/bash

file=${1}

if [ -e $file ]; then
  echo "file exists"
fi

if [ -f $file ]; then
  echo "file exists and is regular"
fi

if [ -r $file ]; then
  echo "file exists and is readable"
fi

if [ -w $file ]; then
  echo "file exists and is writable"
fi

if [ -x $file ]; then
  echo "file exists and is executable"
fi

if [ -e $file -o "1" == "2" ]; then
  echo "file exists or 1 = 2"
fi
