#!/bin/bash

# Easy Builder for C on Linux
# Author: vargalaszlo.com 
# ---
# set files of project
bin=fGen
declare -a sources=("main" "signals" "operands" "outputs" "adjust" "create")
flags="-lm -w"
# creating
if [ ! -d "build" ]; then
	mkdir build
fi
if [ ! -d "bin" ]; then
	mkdir bin
fi
# cleaning
rm -f build/*.*
# compiling
for v in ${sources[@]}
do
   gcc -c src/$v.c -o build/$v.o -I"include" $flags
done
# building
obj=$(printf 'build/%s.o ' "${sources[@]}")
gcc $obj -o bin/$bin $flags


