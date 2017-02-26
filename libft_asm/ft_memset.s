global ft_memset

section .text

ft_memset:
	mov rax, rdi	

loop:
	cmp rdx, 0
	jz end
	mov [rdi], sil
	inc rdi
	dec rdx
	jmp loop

end:
	ret
