#!/bin/bash

# if statement checks number of arguments ("$#") to see if it is NOT equal (-ne) to 2
# if true, which is not what we want, then showcase correct input example & exit with status 1
if [ "$#" -ne 2 ]; then
    echo "Parameters specified INCORRECTLY. Try again ie. $0 filesdir searchstr"
    exit 1
fi

# create variables to assign our 2 arguments to ($1, $2)
filesdir="$1"
searchstr="$2"

# check if filesdir represents a directory on the filesystem
# if statement checks to see if 1st argument (filesdir) is NOT (!) a directory (-d)
# if true, which is not what we want, then notify user and exit with status 1
if [ ! -d "$filesdir" ]; then
    echo "$filesdir directory not found on filesystem"
    exit 1
fi

# create variable of number of files from file path (filesdir)
# find function returns list of files within specified file path (variable filesdir)
# list of files piped into word count function (wc) which return number of lines (-l) in said list
file_count=$(find "$filesdir" -type f | wc -l)

# count number of matching lines within file path, recursively
# grep function searches through content of each file in file path (filesdir) recursively (-r) for specified string (searchstr) & returns list of lines containing said string
# list of lines piped into word count function (wc) which return number of lines (-l) in said list
line_match_count=$(grep -r "$searchstr" "$filesdir" | wc -l)

# prints output message with number of files in specified directory & number of line matches throughout directory
echo "The number of files are $file_count and the number of matching lines are $line_match_count"
