malloc:
 add esp, eax
 ret

memcpy:
 lodsb
 stosb
 or al, al
 jne memcpy

memcmp:
 lodsb
 cmp eax, al
 je memcmp
