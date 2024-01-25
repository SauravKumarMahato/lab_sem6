#!/bin/bash

echo "Enter the first number:"
read a

echo "Enter the second number:"
read b

# Fix: No need for $ before variable names in arithmetic operations
c=$((a + b))

echo "Addition of two given numbers = $c"

