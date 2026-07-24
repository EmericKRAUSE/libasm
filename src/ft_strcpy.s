bits 64

section .text
global ft_strcpy

ft_strcpy:
    mov rax, rdi
    mov rcx, 0
    
.loop:
    mov dl, [rsi + rcx]
    mov [rdi + rcx], dl
    cmp dl, 0
    je .done
    inc rcx
    jmp .loop

.done:
    ret
