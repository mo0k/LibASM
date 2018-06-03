section .text
	global _ft_memcpy

_ft_memcpy:
	xchg rcx, rdx
	cld
	rep movsb
	ret