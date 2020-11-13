#!/bin/bash
#
#Question 2 : In a given fragment of text, delete all the lowercase characters a-z. 
#
if [ -z "$1" ]
then
echo "No argument supplied. Please input string as command line arguments."
else
	temp=$(echo "$1" | sed 's/[a-z]//g')
	echo $temp
fi
