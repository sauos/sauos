global loader           ; making entry point visible to linker
extern kmain            ; kmain is defined elsewhere
 
; setting up the Multiboot header - see GRUB docs for details
MODULEALIGN equ  1<<0                   ; align loaded modules on page boundaries
MEMINFO     equ  1<<1                   ; provide memory map
FLAGS       equ  MODULEALIGN | MEMINFO  ; this is the Multiboot 'flag' field
MAGIC       equ    0x1BADB002           ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + FLAGS)        ; checksum required
 
section .text
align 4
MultiBootHeader:
   dd MAGIC
   dd FLAGS
   dd CHECKSUM
 
; reserve initial kernel stack space
STACKSIZE equ 0x4000                  ; that's 16k.
 
extern start_ctors, end_ctors, start_dtors, end_dtors
 
loader:
   mov esp, stack+STACKSIZE        ; set up the stack
   push eax                        ; Multiboot magic number
   push ebx                        ; Multiboot info structure

; As part of "Roadkill" - the complete fixup of SauOS, C++ is used.
static_ctors_loop:
   mov ebx, start_ctors
   jmp .test
.body:
   call [ebx]
   add ebx,4
.test:
   cmp ebx, end_ctors
   jb .body
 
   call _main                      ; call kernel proper
 
static_dtors_loop:
   mov ebx, start_dtors
   jmp .test
.body:
   call [ebx]
   add ebx,4
.test:
   cmp ebx, end_dtors
   jb .body
 
   hlt                             ; halt machine should kernel return

; GDT function - thx to OSDev guys!
gdtr dw 0 ; For limit storage
     dd 0 ; For base storage
 
setGdt:
   mov   eax, [esp + 4]
   mov   [gdtr + 2], eax
   mov   ax, [esp + 8]
   mov   [gdtr], ax
   lgdt  [gdtr]
   jmp   0x08:reload_CS ; 0x08 points at the new code selector
.reload_CS:
   ; Reload data segment registers:
   mov   ax, 0x10 ; 0x10 points at the new data selector
   mov   ds, ax
   mov   es, ax
   mov   fs, ax
   mov   gs, ax
   mov   ss, ax
   ret

section .bss
align 4
stack:
   resb STACKSIZE