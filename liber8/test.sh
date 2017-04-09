#!/bin/bash

if grep -l "$pattern" liber8.sh > /dev/null
then
        echo "Pattern found in file"
else
        echo "Pattern not found in file"
fi