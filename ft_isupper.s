section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 0x41
	jl false
	cmp rdi, 0x5a
	jg false
	jmp true

false:
	xor rax, rax
	ret

true:
	mov rax, 0x01
	ret
