#!/bin/bash
#
#Question 14 : Given two numbers num1 and num2, write a shell script to find num1 to the power num2. 
#
if [ $# -ne 2 ]
then
	echo "Please input 2 numbers as arguments"
else
echo $1^$2 | bc
fi
