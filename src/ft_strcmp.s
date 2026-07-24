bits 64

section .text
global ft_strcmp

ft_strcmp:
    mov rax, 0
    move rcx, 0

.loop:
    cmp bye [r]
