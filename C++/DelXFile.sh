#!/bin/sh
files=`find . -perm /u+x`
#echo $files
for file in $files
do
#    echo $file
    if [ -f $file ]
    then
        if [[ ! ${file} =~ "DelXFile.sh" ]]
        then
            rm $file
        fi
    fi
done

