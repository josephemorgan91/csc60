#!/bin/bash

file_count=0;

for f in ./* ./.*; do
	if [ ! -d "$f" ] && [ `stat --printf="%s" "$f"` -ge 900 ]; then
		file_count=$((file_count + 1))
	fi
done

echo "$file_count"
