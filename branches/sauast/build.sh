#!/bin/sh

echo ">Compiling Kernel."
gcc -o mainKernel.o -nostdinc -fno-builtin -c mainKernel.c
nasm -f aout bootLoader.asm
ld -T linkScript.x -o sauos bootLoader.o mainKernel.o
