#!/bin/bash
for arg in "$@"
do
strace "/usr/bin/$arg" 2>&1 | grep -o -E '\/[^\/]*\.so.*\"' | tr -d '\/\"' >> output
echo "
" >> output
done
sort -u output | grep -v "^$" >output2
