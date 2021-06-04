#!/bin/bash
a="./a.exe"

g++ *.cpp -o $a $1

echo "in1:"
$a <in1.html -a class -t li -asc
echo ""
echo "in2:"
$a <in2.html -a name