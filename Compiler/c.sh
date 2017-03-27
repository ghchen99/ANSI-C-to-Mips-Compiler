#!/bin/bash
echo "--------------------------------------------"
cat test/tmp.c 
echo "--------------------------------------------"
mips-linux-gnu-gcc -static test/tmp.c -o test/tmp.elf
qemu-mips test/tmp.elf
echo $?
echo "--------------------------------------------"
