mboothdr:
	dd 0x1badb002
        dd 0x00010003
	dd (0x1badb002 + 0x00010003)
	dd mboothdr
	dd _sauos_start
	dd edata
	dd _sauous_end
	dd _sauous_init

_sauos_start:
	mov esp, stack + 0x4000
	push $0
	popf
	push ebx
	push eax
	call _sauos_cmain
	jmp $

stack:	resb 0x4000
