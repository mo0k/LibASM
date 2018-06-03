section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10
	mov r15, rdi		;save str
	call _ft_strlen
	add rax, 0x01 		;add /0
	mov r14, rax		;save len
	mov rdi, r14
	call _malloc
	mov rdi, rax
	mov rsi, r15
	mov rcx, r14
	cld
	rep movsb
	leave
	ret

