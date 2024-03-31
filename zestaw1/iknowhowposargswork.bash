#!/bin/bash
#  iknowhowposargswork
i=$(($#))
FOO=$1
BAR=$2
# i zmienna przechowujaca ilosc parametrow
echo -n "You give me $i parametrs: "
i=$((i-1))
while [ $i -ge 0 ];
do
        echo -n ${BASH_ARGV[$i]}
        echo -n " "
        i=$((i-1))
done
echo
echo "The first two are: $FOO, $BAR"