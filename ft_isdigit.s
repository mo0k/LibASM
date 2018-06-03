section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, 0x30
	jl false
	cmp rdi, 0x39
	jg false
	jmp true

false:
	xor rax, rax
	ret

true:
	mov rax, 0x01
	ret