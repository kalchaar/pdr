#!/bin/bash

# Keenan Alchaar | ka5nt | 04/09/2021 | averagetime.sh

echo "enter the exponent for counter.cpp:"
read exponent
if [[ "$exponent" == "quit" ]] ; then
   exit 1
fi
totalTime=0
averageTime=0
for i in {1..5} ; do
    echo "Running iteration" $i"..."
    RUNNING_TIME_temp=`./a.out $exponent`
    echo "time taken:" $RUNNING_TIME_temp "ms"
    totalTime=$((totalTime+RUNNING_TIME_temp))
done
averageTime=$((totalTime/5))
echo "5 iterations took" $totalTime "ms"
echo "Average time was" $averageTime "ms"
