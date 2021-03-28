#!/bin/bash

arr_size=500

declare -a array

for i in {1..500}
do
	array[i - 1]=$i
done

array=( $(shuf -e "${array[@]}") )
printf "%s " ${array[@]}
