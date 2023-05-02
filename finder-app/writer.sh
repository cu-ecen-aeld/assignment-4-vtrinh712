#!/bin/bash

# check number of arguments ("$#") to see if it is NOT equal (-ne) to 2
# if true, which is not what we want, then showcase correct input example & exit
if [ "$#" -ne 2 ]; then
    echo "Parameters specified INCORRECTLY. Try again ie. $0 writefile writestr"
    exit 1
fi

# create variables to assign our 2 arguments to ($1, $2)
writefile="$1"
writestr="$2"

# create specified file, without affecting possible already-existing file (mkdir), with parent directories (-p)
mkdir -p "$(dirname "$writefile")"

# (over)write (echo) content (writestr) into file (writefile)
echo "$writestr" > "$writefile"

# check if file was created successfully; otherwise, showcase correct input example & exit
if (! echo "$writestr" > "$writefile"); then
    echo "File could not be created. Try again ie. $0 writefile writestr"
    exit 1
fi
