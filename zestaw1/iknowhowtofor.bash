#!/bin/bash
# iknowhowtofor
t=("I used Windows" "I used MacOs" "I used Linux" "I must try BSD")
for n in ${t[@]};
do
        echo -n $n
        echo -n " "
        if [ $n = Windows ]
        then
                echo " "
        elif [ $n = MacOs ];
        then
                echo " "
        elif [ $n = Linux ];
        then
                echo " "
        elif [ $n = BSD ];
        then
                echo " "
        fi
done