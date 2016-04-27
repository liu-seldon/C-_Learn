#!/bin/sh
# rm *.o
find -name *.o | xargs rm
# find all files that can be executable
files=`find . -perm /u+x | grep -v "DelXFile" `
# echo $files
for file in $files
do
#    echo $file
    if [ -f $file ]
    then
        rm $file
    fi
done

