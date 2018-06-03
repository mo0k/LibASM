section .text
	global _ft_isalpha
	global is_major

_ft_isalpha:
	cmp rdi, 0x5a
	jg is_major
	cmp rdi, 0x41
	jl false
	jmp true

is_major:
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
