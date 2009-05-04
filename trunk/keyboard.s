read_kbd:
 in al,64h       ; read status byte
 and al,01h      ; wait for OBF==1
 jz read_kbd
 in al,60h       ; read scancode byte
 push al
 call sc2ascii
 mov esi, eax
 call kputs
 ret