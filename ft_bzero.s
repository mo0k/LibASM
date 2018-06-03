section .text
	global _ft_bzero

_ft_bzero:
	mov rcx, rsi
	xor rax, rax
	cld
	rep stosb
	ret