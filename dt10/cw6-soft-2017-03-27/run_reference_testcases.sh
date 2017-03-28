#!/bin/bash

COMPILER=bin/c_compiler

TESTDIR=$1

mkdir -p working

for DRIVER in $TESTDIR/*_driver.c ; do
    NAME=$(basename $DRIVER _driver.c)
    TEST=$TESTDIR/$NAME.c

    >&2 echo "-----------------------------------------------------"    
    >&2 echo "Test case $NAME"
    
    # Compile driver with normal GCC
    mips-linux-gnu-gcc -c $DRIVER -o $TESTDIR/${NAME}_driver.o 2> $TESTDIR/${NAME}_driver.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR: Couldn't compile driver program using GCC."
        continue
    fi
    
    # Compile test function with compiler under test to assembly
    cat $TEST | $COMPILER > $TESTDIR/$NAME.s  2> $TESTDIR/${NAME}.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR: Compiler returned error message."
        continue
    fi
    
    # Link driver object and assembly into executable
    mips-linux-gnu-gcc -static $TESTDIR/${NAME}.s $TESTDIR/${NAME}_driver.o -o $TESTDIR/${NAME}.elf 2> $TESTDIR/${NAME}.link.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR: Linker returned error message."
        continue
    fi
    
    # Run the actual executable
    qemu-mips $TESTDIR/${NAME}.elf
    RES=$?
    if [[ $RES -ne 0 ]]; then
        >&2 echo "ERROR: Testcase returned $RES, but expected 0."
        continue
    fi

    >&2 echo "pass"
    >&2 echo ""
done
