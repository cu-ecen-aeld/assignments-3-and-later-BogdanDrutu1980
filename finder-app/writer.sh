#!/bin/bash
if [ $# -ne 2 ]; then
	echo "Error: Invalid number of arguments"
	exit 1
fi

writefile="$1"
writestr="$2"

#Create directory if it does not exist
dir_path=$(dirname "$writefile")
mkdir -p "$dir_path"
if [ $? -ne 0 ]; then
	echo "Error: Failed to create directory path"
	exit 1
fi
#Create/overwrite the file with the content provided by argument
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
	echo "Error: File couldnt be created!"
	exit 1
fi
