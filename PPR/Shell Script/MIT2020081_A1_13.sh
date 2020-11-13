#!/bin/bash
#
#Question 13 : Given a number, find the sum of digits of the number
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
	sum=`expr $sum + $digit`
	temp=`expr $temp / 10`
done
echo $sum
fi
