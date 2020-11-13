#!/bin/bash
#
#Question 5 : Write a programme to check if the number is palindrome or not. Return in “Yes” or “No”.
#
if [ -z $1 ]
then
	echo "Please input number as argument"
else
temp=$1
sum=0
while [ $temp -gt 0 ]
do
	digit=`expr $temp % 10`
	sum=`expr \( $sum \* 10 \) + $digit`
	temp=`expr $temp / 10`
done
	
if [ $1 -eq $sum ]
then
	echo "Yes"
else
	echo "No"
fi
fi
