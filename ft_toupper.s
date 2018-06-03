section .text
	global _ft_toupper
	extern _ft_islower

_ft_toupper:
	call _ft_islower
	cmp rax, 0x1
	je upper
	mov rax, rdi
	ret

upper:
	sub rdi, 0x20
	mov rax, rdi
	ret