section .text
	global _ft_isascii

_ft_isascii:
	cmp rdi, 0x0
	jl false
	cmp rdi, 0x7f
	jg false
	jmp true

false:
	xor rax, rax
	ret

true:
	mov rax, 0x01
	ret
