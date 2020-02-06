#!/bin/bash

total_size=0

function get_file_size() {
	file_size=`stat --printf="%s" $1`
	echo "$file_size"
}

function add_file_sizes() {
	for f in * ./.*; do
		echo "Currently processing: $f"
		if [[ -d $f ]] && [[ $1 == -r ]]; then
			echo "$f is a directory"
			if [[ "$f" !=  "./." ]] || [[ "$f" != "./.." ]]; then
				echo "$f is not ./. or ./.."
				cd "$f"
				pwd
				add_file_sizes -r
				echo "$total_size"
				cd ../
			fi
		fi
		if [[ ! -d "$f" ]]; then
			echo "$f is not a directory"
			total_size=$((total_size + $(get_file_size $f)))
			echo "$total_size"
		fi
	done
}

add_file_sizes $1

echo "$total_size"
