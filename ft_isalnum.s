section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 0x01
	je true
	call _ft_isdigit
	cmp rax, 0x01
	je true
	jmp false

false:
	xor rax, rax
	ret

true:
	mov rax, 0x01
	ret
