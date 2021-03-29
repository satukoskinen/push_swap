#!/bin/bash

if [ $# == 2 ]
then
	arr_size=$1
	repeat=$2
else
	printf "usage: $0 arr_size repeat\n"
	exit 1
fi

generate_input () {
	local start=0
	local end=$arr_size
	local i
	declare -a array

	for (( i=$start; i<$end; i++ ))
	do
		array[$i]=$i
	done
	array=( $(shuf -e "${array[@]}") )
	printf "%s " ${array[@]}
}

for (( i=0; i<=$repeat; i++ ))
do
	test_args="test_args_${arr_size}_${i}"
	generate_input > $test_args
	./push_swap $test_args | ./checker $test_args > output
	grep "KO" output > fail
	if [ -s fail ]
	then
		printf "./push_swap $test_args | ./checker $test_args > output: KO\n"
		exit 1
	else
		printf "OK:"
	fi
	./push_swap $test_args | wc -l > count
	cat count
	rm -f fail output count $test_args
done

