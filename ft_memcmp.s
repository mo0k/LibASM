section .text
	global _ft_memcmp

_ft_memcmp:			
	xchg rcx, rdx
	cld
	rep cmpsb
	movzx rax, byte [rdi-1]
	movzx r15, byte [rsi-1]
	sub rax, r15
	ret