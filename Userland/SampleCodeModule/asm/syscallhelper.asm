GLOBAL _sys_write
GLOBAL _sys_read
GLOBAL _sys_drawRectangle
GLOBAL _sys_clearScreen
GLOBAL _sys_getCoords
GLOBAL _sys_undrawChar

section .text

%macro syscall 1
    mov rax, %1
    int 80h
    ret
%endmacro

_sys_read: syscall 0x00
_sys_write: syscall 0x01
_sys_drawRectangle: syscall 0x02
_sys_clearScreen: syscall 0x03
_sys_getCoords: syscall 0x04
_sys_undrawChar: syscall 0x05