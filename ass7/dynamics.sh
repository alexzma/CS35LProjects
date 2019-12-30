#!/bin/bash
libs=""
for arg in "$@"
do
temp=$(ldd "/usr/bin/$arg" | sed -r 's/^\s//g' | sed -r 's/ =.*//g' | sed -r 's/ \(.*//g')
libs="$libs$temp
"
done
echo "$libs" | sed -r 's/not a dynamic executable//g' | sort -u
