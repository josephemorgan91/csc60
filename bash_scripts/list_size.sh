#!/bin/bash

total_size=0

get_file_size() {
	stat --printf="%s" "$1"
}

add_file_sizes() {
	for f in ./* ./.*; do
		if [ ! -d "$f" ]; then
			total_size=$((total_size + $(get_file_size "$f")))
		fi
	done
}

add_file_sizes $1

echo "$total_size"
