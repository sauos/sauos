extern _sauos_cmain
global __stack_chk_fail
global _sauos_init

mboothdr:
	dd 0x1badb002
        dd 0x00010003
	dd (0x1badb002 + 0x00010003)

_sauos_init:
	mov esp, stack + 0x4000
	push $0
	popf
	push ebx
	push eax
	call _sauos_cmain
	jmp $

; GCC!!!!!!!!!!!!
__stack_chk_fail:
	ret

.bss
stack:	resb 0x4000
