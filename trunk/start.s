%define MBOOT_MAGIC 0x1badb002
%define MBOOT_FLAGS 0x00010002

bits 32
org 0x100000
extern kmain

__entry_point:
 ; Load new GDT ...
 lgdt [gdtr]
 mov ax, 0x10
 mov ds, ax
 mov es, ax
 mov fs, ax
 mov gs, ax
 mov ss, ax
 jmp 0x08:__entry_point2

__entry_point2:
 mov esp, stack
 call kmain
 jmp $

align 4, db 0
header:
 dd MBOOT_MAGIC
 dd MBOOT_FLAGS
 dd 0 - MBOOT_MAGIC - MBOOT_FLAGS
 dd header
 dd __entry_point
 dd end_of_file
 dd end_of_file
 dd __entry_point

gdt:
 dd 0, 0
 db 0xFF, 0xFF, 0, 0, 0, 10011010b, 11001111b, 0x40
 db 0xFF, 0xFF, 0, 0, 0, 10010010b, 11001111b, 0x40

gdtr:
 dw 17
 dd gdt

stack:
 resb 8192

align 4, db 0
end_of_file:
