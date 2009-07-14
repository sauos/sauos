#!/bin/sh

echo ">Compiling Kernel."
gcc -o mainKernel.o -nostdinc -fno-builtin -c mainKernel.c
gcc -o vsprintf.o -nostdinc -fno-builtin -c vsprintf.c
nasm -f aout bootLoader.asm
ld -T linkScript.x -o sauos bootLoader.o mainKernel.o vsprintf.o
rm *.o
echo ">Done - Result Binary Is 'sauos'"
