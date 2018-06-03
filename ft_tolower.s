section .text
	global _ft_tolower
	extern _ft_isupper

_ft_tolower:
	call _ft_isupper
	cmp rax, 0x1
	je lower
	mov rax, rdi
	ret

lower:
	add rdi, 0x20
	mov rax, rdi
	ret