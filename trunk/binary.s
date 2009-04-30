extern access_addr
extern stack
; Run binary file in ecx.
sys_execv:
 ; Install the user stack
 mov esp, user_stack
 ; Copy the binary to a free space
 mov esi, ecx
.find_free_addr:
 mov ecx, [paddr]
 call access_addr
 cmp eax, 0
 jz .copy_bin_loop
 inc [paddr]
 jmp .find_free_addr
.copy_bin_loop:
 mov edi, [paddr]
 lodsb
 stosb
 or al, al
 jne .copy_bin_loop
.call_binary:
 call [paddr]
 mov esp, stack
 ret

paddr dd 0x8000000
user_stack:
 resb 32044
