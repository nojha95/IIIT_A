#!/bin/bash
#
#Question 3 : In a given fragment of text, replace all sequences of multiple spaces with just one space.  
#
if [ -z "$1" ]
then
echo "No argument supplied. Please input string as command line arguments."
else
	temp=$(echo "$1" | sed 's/ \+/ /g')
	echo $temp
fi
