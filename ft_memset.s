section .text
	global _ft_memset

_ft_memset:
	mov r15, rdi
	mov rcx, rdx
	mov rax, rsi 
	cld
	rep stosb
	mov rax, r15
	ret