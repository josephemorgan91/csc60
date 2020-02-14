#!/bin/bash

for dir in ./*; do
	if [ -d "$dir" ]; then
		echo "decending into dir $dir"
		cd "$dir"
		for f in *.c; do
			echo "compiling $f"
			gcc "$f" -Wall -pedantic -o test.out
		done
		cd ../
	fi
done
