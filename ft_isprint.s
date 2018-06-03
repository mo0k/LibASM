section .text
	global _ft_isprint

_ft_isprint:
	cmp rdi, 0x20
	jl false
	cmp rdi, 0x7e
	jg false
	jmp true

false:
	xor rax, rax
	ret

true:
	mov rax, 0x01
	ret
