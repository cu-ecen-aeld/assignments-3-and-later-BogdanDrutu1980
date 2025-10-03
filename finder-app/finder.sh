#!/bin/bash

# Verify the number of arguments
if [ $# -ne 2 ]; then
       	echo "Error: Invalid number of arguments"
	exit 1
fi

filesdir="$1"
searchstr="$2"

if [ ! -d "$filesdir" ]; then
	echo "Error: '$filesdir' is not a directory!"
	exit 1
fi

file_count=0
match_count=0

file_count=$(find "$filesdir" -type f | wc -l)
echo $file_count
match_count=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)
echo "The number of files are $file_count and the number of matching lines are $match_count"

