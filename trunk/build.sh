#!/bin/sh

# ScorchOS Build Script (Linux)
# Copyright (C) 2008-9 ScorchOS Developers
# For Terms see apl.txt and license.txt

echo '> Starting Build...'

# This makes sure the user is root (needed for the loop-back mount of the floppy
# image I created earlier with a grub bootloader
if test "`whoami`" != "root" ; then
	echo "You must be logged in as root to build (for loopback mounting)"
	echo "Enter 'su' or 'sudo bash' to switch to root"
	exit
fi

cd src
echo '> Assembling Bootloader...'
# Compile bootloader
nasm -f elf -o start.o start.asm

echo '> Assembling ApolloOS Kernel Source...'
#Compile Kernel Modules (C Programming Language)
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o main.o -c main.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o scrn.o -c scrn.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o gdt.o -c gdt.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o idt.o -c idt.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o isrs.o -c isrs.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o irq.o -c irq.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o timer.o -c timer.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fleading-underscore -I./include -o kb.o -c kb.c

echo '> Creating Kernel Binary...'
# Links the kernel modules together into a single binary
ld -T link.ld -o kernel.x start.o main.o scrn.o gdt.o idt.o isrs.o irq.o timer.o kb.o


#cd ..
#echo '> Adding Kernel and Apps to Floppy Image...'
#Time for that loop-back mount!
#rm -rf tmp-loop

#mkdir tmp-loop && mount -o loop -t vfat disk_image/sau.img tmp-loop
# Remove previous kernel.x before adding the new one...
#cd tmp-loop && rm -rf kernel.x && cd ..
#cp src/kernel.x tmp-loop/kernel.x

# Move included program binaries onto the floppy image (uncomment to use)
#cp app/*.bin tmp-loop
#echo '> Unmounting Loop-back Floppy...'
# Unmount the loop-back floppy
#umount tmp-loop || exit
#rm -rf tmp-loop

#echo '> Quick Cleanup...'
# A quick cleanup (comment this out while debugging)
#cd src
#rm *.o
#rm *.x
#cd ..
# Note that (unlike MikeOS) you are not expected to carry source code in the
# app directory - just the binaries. You can add additional build and
# cleanup routines if you'd prefer to include souce however

echo '> Build Complete!'
