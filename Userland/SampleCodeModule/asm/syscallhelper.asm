GLOBAL _sys_write
GLOBAL _sys_read

section .text

%macro syscall 1
    mov rax, %1
    int 80h
    ret
%endmacro

_sys_read: syscall 0x00
_sys_write: syscall 0x01