#!/bin/bash
#
#Question 6 : Reverse the string. 
#
if [ -z "$1" ]
then
echo "Please input string as command line argument."
else
	str=$1
	rev=""
	len=`expr length "$str"`
	len=`expr $len - 1`
	while [ $len -ge 0 ]
	do
		rev=${rev}${str:$len:1}
		len=`expr $len - 1`
	done
	echo $rev
fi
