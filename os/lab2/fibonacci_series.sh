#!/bin/bash

echo "Enter the number of terms in the Fibonacci series:"
read n

a=1
b=1

echo "Fibonacci series:"
for (( i=0; i<n; i++ )); do
    echo -n "$a "
    temp=$((a + b))
    a=$b
    b=$temp
done

echo

