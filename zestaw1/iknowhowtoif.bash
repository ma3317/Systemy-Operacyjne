#!/bin/bash
#  iknowhowtoif
echo "What is your favourite OS?"
read napis
if [ $napis = Windows ]
then
        echo "I used Windows once. What is that blue screen for?"
elif [ $napis = MacOs ]; then
        echo "Your OS can do anything as long as it is in AppStore."
elif [ $napis = Linux ]; then
        echo "Linux is free if your time is worthless"
else
        echo "Is $napis an operating system?"
fi