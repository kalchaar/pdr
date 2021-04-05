#!/bin/bash

# Keenan Alchaar | ka5nt | 03/30/2021 | averagetime.sh

echo "Please enter the name of the dictionary file:"
read dictionaryFileName
echo "Please enter the name of the grid file:"
read gridFileName

RUNNING_TIME_0=`./a.out $dictionaryFileName $gridFileName | tail -1`
RUNNING_TIME_1=`./a.out $dictionaryFileName $gridFileName | tail -1`
RUNNING_TIME_2=`./a.out $dictionaryFileName $gridFileName | tail -1`
RUNNING_TIME_3=`./a.out $dictionaryFileName $gridFileName | tail -1`
RUNNING_TIME_4=`./a.out $dictionaryFileName $gridFileName | tail -1`

totalTime=$((RUNNING_TIME_0 + RUNNING_TIME_1 + RUNNING_TIME_2 + RUNNING_TIME_3 + RUNNING_TIME_4))
averageTime=$((totalTime / 5))

echo "The average run time is" $averageTime "ms."
