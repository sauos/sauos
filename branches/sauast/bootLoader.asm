EXTERN SauOSMain

; Just in case if our bootloader loads 32-bit flat images...
jmp SauOSStart

ALIGN 4, DB 0

MultiBootHeader:
 dd	0x1BADB002
 dd	1<<0 | 1<<1 | 1<<16
 dd	-(0x1BADB002 + (1<<0 | 1<<1 | 1<<16))
 dd	MultiBootHeader
 dd	code
 dd	bss
 dd	EndKernel
 dd	SauOSStart

code db 0

SauOSStart:
	mov	esp, Kernel_Stack
	call	SauOSMain
	jmp	$

.bss
bss db 0
Kernel_Stack:
; 8K Kernel Stack
	resb	8192

extern EndKernel
