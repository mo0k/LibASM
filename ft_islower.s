section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 0x61
	jl false
	cmp rdi, 0x7a
	jg false
	jmp true

false:
	xor rax, rax
	ret

true:
	mov rax, 0x01
	ret
