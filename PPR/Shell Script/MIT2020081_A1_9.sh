#!/bin/bash
#
#Question 9 : Given a string returns the same string in lowercase. 
#
if [ -z "$1" ]
then
echo "No argument supplied. Please input string as command line arguments."
else
	echo $1 | sed 's/[A-Z]/\L&/g'
fi
