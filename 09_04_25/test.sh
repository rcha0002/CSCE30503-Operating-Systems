#! /bin/bash

./sep4 < $1 > output.txt
cmp output.txt $2

if [ $? == 0 ]; then
    echo "Test Passed"
else
    echo "Test Failed"
fi
