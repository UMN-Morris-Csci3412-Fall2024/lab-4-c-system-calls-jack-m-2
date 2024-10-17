#!/bin/bash

# Ensure an argument was provided.
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <path>"
  echo "       where <path> is the file or root of the tree you want to summarize."
  exit 1
fi

path=$1

# Check if the provided path exists
if [ ! -e "$path" ]; then
  echo "The path '$path' does not exist."
  exit 1
fi

# Count the number of directories
num_dirs=$(find "$path" -type d | wc -l)

# Count the number of regular files
num_regular=$(find "$path" -type f | wc -l)

echo "There were $num_dirs directories."
echo "There were $num_regular regular files."