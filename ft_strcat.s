section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	lea r15, [rel rdi]
	xor rax, rax
	mov rcx, -1
	cld
	repne scasb
	dec rdi
	mov r14, rsi
	xchg rdi, rsi
	call _ft_strlen
	mov rcx, rax
	inc rcx
	xchg rdi, rsi
	xchg rsi, r14
	rep movsb
	mov rax, r15
	ret
