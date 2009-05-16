; HorseOS ATA driver
; Uses ports

;ata_read - al = drive and head, bl = beginning sector
;reads 1 sector
global ata_lowlevel_read
ata_lowlevel_read:
   mov     ebx, eax
   xchg    al, bl
   add     al, bh
   mov     dx,1f6h         ;Drive and head port
   out     dx,al

   mov     dx,1f2h         ;Sector count port
   mov     al,1
   out     dx,al

   mov     dx,1f3h         ;Sector number port
   mov     al,bl
   out     dx,al

   mov     dx,1f4h         ;Cylinder low port
   mov     al,0            ;Cylinder 0
   out     dx,al

   mov     dx,1f5h         ;Cylinder high port
   mov     al,0            ;The rest of the cylinder 0
   out     dx,al

   mov     dx,1f7h         ;Command port
   mov     al,20h          ;Read with retry.
   out     dx,al
.still_going:
   in      al,dx
   test    al,8            ;This means the sector buffer requires
            ;servicing.
   jz      .still_going     ;Don't continue until the sector buffer
            ;is ready.

   mov     cx, 512
   mov     edi,[buffer]
   mov     dx,1f0h         ;Data port - data comes in and out of here.
   rep     insw
   mov     eax,[buffer]
   ret

global buffer
buffer: db 0
