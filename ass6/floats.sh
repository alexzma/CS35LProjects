#!/bin/bash
num=$((2**24*4))
od -t fF -N $num </dev/urandom | sed -r 's/^[0-9]*[ ]*//g' | 
sed -r 's/[ ]+[ ]+/ /g' | tr ' ' '\n' | tr '\n' 'P' | sed 's/PP/P/g' | 
tr 'P' '\n' | head -c -1 >floaty.txt
