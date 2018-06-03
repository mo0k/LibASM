section .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0x0
	mov rcx, -0x1
	cld
	repne scasb
	not rcx
	dec rcx
	mov rax,rcx
	ret