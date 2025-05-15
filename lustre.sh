#!/bin/bash

input_file="$1"

# Check if the input file is provided
if [ -z "$input_file" ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

# Check that the input file ends in .lus
if [[ "$input_file" == *.lus ]]; then
    echo "Running lv6 on $input_file"

    fileName=$(basename "$input_file")
    fileName="${fileName%.*}"

    nodes=$(grep -E '^[[:space:]]*node[[:space:]]+' "$input_file" | awk '{print $2}')
    echo "$nodes"

    # If there are no nodes, we give an error
    if [ -z "$nodes" ]; then
        echo "No nodes found in $input_file"
        exit 1
    fi

    # If there is only one node, we can run it directly
    if [ $(echo "$nodes" | wc -l) -eq 1 ]; then
        node=$(echo "$nodes" | tr -d '\n')
        echo "Running lv6 on $input_file with node $node"
        lv6 "$input_file" -n "$node" -2c-exec
        exit 1
    fi

    # We try with the basename of the file
    echo "Trying with: $fileName"

    if
        lv6 "$input_file" -n "$fileName" --output-file /dev/null >/dev/null 2>&1
    then
        echo "It works with $input_file"
        lv6 "$input_file" -n "$fileName" -2c-exec
        exit
        exit 0
    fi

fi
