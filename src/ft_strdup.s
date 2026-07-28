bits 64

section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    call ft_strlen
    inc rax

    push rdi
    mov rdi, rax

    call malloc wrt ..plt

    pop rsi

    cmp rax, 0
    je .error

    mov rdi, rax
    call ft_strcpy

    ret

.error:
    ret
