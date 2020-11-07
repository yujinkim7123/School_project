#!/bin/bash

gcc -o isPrimeNumber main.c 

read n
n=`expr $n + 1`
i=1

cat /dev/null > log.txt

while [ $i -ne $n ]; do

a=`./isPrimeNumber $i`

if [ $a -eq "1" ];
then
echo "$i">>log.txt
fi
i=`expr $i + 1`
done

exit 0


