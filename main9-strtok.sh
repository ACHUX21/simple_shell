#!/bin/bash

for i in $(ls automated_checker/tests/simple_shell_strtok/); do
    echo -e "\e[31m$i\e[0m"
    ./automated_checker/checker ./hsh ./automated_checker/tests/simple_shell_strtok/$i
    echo
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
done
for i in $(ls automated_checker/tests/simple_shell_strtok/); do
    echo -e "\e[31m$i\e[0m"
    ./automated_checker/run ./hsh ./automated_checker/checker ./automated_checker/tests/simple_shell_strtok/$i
    echo
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
done