#!/bin/bash

for dir in ./*; do
	if [ -d "$dir" ]; then
		echo "decending into dir $dir"
		cd "$dir"
		for f in *.c; do
			echo "compiling $f"
			gcc "$f"
		done
		cd ../
	fi
done
