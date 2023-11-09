#!/bin/bash

for i in $(ls automated_checker/tests/simple_shell_setenv_unsetenv/); do
    echo -e "\e[31m$i\e[0m"
    ./automated_checker/checker ./hsh ./automated_checker/tests/simple_shell_setenv_unsetenv/$i
    echo
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
    echo "================================================================ ============================================================================================="
done