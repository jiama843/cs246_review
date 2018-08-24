#!/bin/bash
# countWords word file
#  Prints the number of times word occurs in file

x=0
for word in $(cat "$2"); do
  if [ $word == "$1" ]; then
    x=$((x + 1))
    echo $((x + 1 + 1))
    #echo $x + 1
  fi
done
echo ${#}
echo ${@}
#echo ${$}
echo $x
