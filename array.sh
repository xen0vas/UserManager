#!/bin/bash

str=`uname -a` 

IFS=' ' # space is set as delimiter
read -ra ADDR <<< "$str" # str is read into an array as tokens separated by IFS
for i in "${ADDR[@]}"; do # access each element of array
     if [ "$i" = "Debian" ]; then
         echo "found $i"
     fi
done
