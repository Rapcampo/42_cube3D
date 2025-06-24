#!/bin/bash

#set -x
test_file="invalid_maps.txt"

echo "\n\n\n \e[1;32mINVALID MAPS!\e[0m"

while IFS= read -r command; do
    echo "Executing map: $command"
    valgrind -q --leak-check=full --show-leak-kinds=all ./cub3D $command
    #echo "$command" | ./minishell
done < "$test_file"

test_file="valid_maps.txt"

echo "\n\n\n \e[1;31mVALID MAPS!\e[0m"

while IFS= read -r command; do
    echo "Executing map: $command"
    valgrind -q --leak-check=full --show-leak-kinds=all ./cub3D $command
    #echo "$command" | ./minishell
done < "$test_file"
