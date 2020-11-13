#!/bin/bash
#Question 11 : Check whether given strings are palindrome. 
#
if [ -z "$1" ]
then
echo "Please input string as command line argument."
else
	#str=$1
	rev=""
	str=$(echo "$1" | sed 's/[A-Z]/\L&/g' | sed 's/[^a-z0-9]//g')
	#echo $str
	len=`expr length "$str"`
	len=`expr $len - 1`
	while [ $len -ge 0 ]
	do
		rev=${rev}${str:$len:1}
		len=`expr $len - 1`
	done
	if [ "$str" == "$rev" ]
	then
		echo "Yes"
	else
		echo "No"
	fi
fi
