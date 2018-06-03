%define SYSCALL(nb)	0x2000000 | nb
%define BUFF_LEN 	4096
%define WRITE 		4
%define READ 		3
%define STDOUT 		1

section .bss
	buf:resb BUFF_LEN

section .text
	global _ft_cat

_ft_cat:
	mov r15, rdi
	jmp start
start:
	mov rdi, r15
	lea rsi, [rel buf]
	mov rdx, BUFF_LEN
	mov rax, SYSCALL(READ)
	syscall
	jc exit
	cmp rax, 0x1
	jl exit
	mov rdi, STDOUT
	lea rsi, [rel buf] ; sans doute inutile
	mov rdx, rax
	mov rax, SYSCALL(WRITE)
	syscall
	jmp start

exit:
	ret
