#!/bin/bash
x=2  # Number of files subtract 1

for N in {1..50}
do
   y=$(($N%$x))
   ((y++))
   ruby client.rb ex$y &
done
wait
