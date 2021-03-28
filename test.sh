#!/bin/bash

arr_size=500

declare -a array

for i in {1..50}
do
	array[i - 1]=$i
done

array=( $(shuf -e "${array[@]}") )
printf "%s " ${array[@]}
