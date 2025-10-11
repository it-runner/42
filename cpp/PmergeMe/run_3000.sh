#!/bin/bash

numbers=$(shuf -i 1-100000 -n 3000)

 # buffer which contains all the numbers and is visible in still reachable:
numbers_str=$(echo $numbers | tr '\n' ' ')

# print numbers after ./run.sh:
# echo $numbers_str

./PmergeMe $numbers_str
