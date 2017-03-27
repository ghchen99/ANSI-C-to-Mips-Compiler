#!/bin/bash
make clean
make bin/c_compiler
echo "--------------------------------------------"
cat test/tmp.c | bin/c_compiler > test/tmp.s 
cat test/tmp.s
echo "--------------------------------------------"
mips-linux-gnu-gcc -static test/tmp.s -o test/tmp.elf
qemu-mips test/tmp.elf
echo $?
echo "--------------------------------------------"

