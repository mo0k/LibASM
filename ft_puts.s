%define SYSCALL(nb)	0x2000000 | nb
%define WRITE		4
%define STDOUT		1

section .data
null:
	.string db "(null)", 10
	.len equ $ - null.string

ret_line:
	.string db 0x0a,0x00, 0

section .text
	global _ft_puts

;notes add \n
_ft_puts:
	cmp rdi, 0
	je exit_null
	xor rax, rax
	mov r15, rdi
	mov rcx, -0x1
	cld
	repne scasb
	not rcx
	sub rcx, 1
	lea rsi, [rel r15]
	mov rdi, STDOUT
	mov rdx, rcx
	mov rax, SYSCALL(WRITE)
	syscall
	mov rdi, STDOUT
	lea rsi, [rel ret_line.string]
	mov rdx, 2
	mov rax, SYSCALL(WRITE)
	syscall
	mov rax, 0x0a
	ret

exit_null:
	mov rdi, STDOUT
	lea rsi, [rel null.string]
	mov rdx, null.len
	mov rax, SYSCALL(WRITE)
	syscall
	mov rax, 0x0a
	ret