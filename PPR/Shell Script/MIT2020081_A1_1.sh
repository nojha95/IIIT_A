#!/bin/bash
#Question 01 - In a given fragment of text, replace all parentheses () with box [] brackets.
#
if [ -z "$1" ]
then
echo "No argument supplied. Please input string as command line arguments."
else
	
	temp=$(echo $1 | sed 's/(/[/g' | sed 's/)/]/g')
	echo $temp
fi
