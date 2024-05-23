GLOBAL cpuVendor
GLOBAL _getScancode
GLOBAL _checkKeyboardBuffer
GLOBAL _readTime

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

_getScancode:
    xor rax, rax
    in al, 0x60
    ret

_readTime:
    push dx
    mov dx, 0x70
    mov al, dil
    out dx, al
    xor rax, rax
    in al, 0x71
    pop dx
    ret
