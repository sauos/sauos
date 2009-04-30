read_kbd:
 in al,64h       ; read status byte
 and al,01h      ; wait for OBF==1
 jz read_kbd
 in al,60h       ; read scancode byte
 ret

sc2ascii:
.loop:
 cmp al, [scodes]
 inc ecx
 je .pt2
 inc [scodes]
 jmp .loop
.pt2:
 ; id the scancode. we saved a counter.
 inc ebx
 cmp ebx, ecx
 je .pt2
 inc [codes]
 jmp .pt2
.yay:
 mov eax, [codes]
 ret

codes: db "`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./ "
scodes: db 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1e, 1f, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 2b, 2c, 2d, 2e, 2f, 30, 31, 32, 33, 34, 35, 39
