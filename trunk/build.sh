#!/bin/sh
echo Now assembling, compiling, and linking your kernel:
nasm -f aout -o start.o start.asm
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o main.o main.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o gdt.o gdt.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o idt.o idt.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o isrs.o isrs.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o irq.o irq.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o timer.o timer.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o kb.o kb.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o vsprintf.o vsprintf.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o ata_c.o ata_c.c
gcc -Wall -Os -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -c -o paging.o paging.c
for f in *.o; do
 strip -R.comment --strip-debug $f
done
nasm -f aout -o ata.o ata.s
ld -T link.ld -o kernel.bin start.o main.o scrn.o gdt.o idt.o isrs.o irq.o timer.o kb.o ata.o ata_c.o vsprintf.o paging.o
#objcopy -R.comment -Obinary kernel.bin
echo Cleaning up object files...
rm *.o
echo Done!
