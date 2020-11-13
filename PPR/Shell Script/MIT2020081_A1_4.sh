#!/bin/bash
#
#Question 4 : Given a list of words order them in lexicographical order.(words will be in Lower case only)  
#
if [ -z "$1" ]
then
	echo "No argument supplied. Please input string as command line arguments."

else
	echo "$1" | sed 's/ \+/\n/g' | sort | tr "\n" " " 
	echo ""
fi
