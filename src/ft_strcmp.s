bits 64

section .text
global ft_strcmp

;rdi = pointer to s1
;rsi = pointer to s2

ft_strcmp:
    mov rcx, 0

.loop:
    mov dl, byte [rdi + rcx]
    mov al, byte [rsi + rcx]

    cmp dl, al
    jne .done

    cmp dl, 0
    je .done

    inc rcx
    jmp .loop

.done:
    ;movzx copies the byte (8 bits) and pads the upper 24bits with zeros
    mov r8b, al;
    movzx eax, dl
    movzx edx, r8b
    sub eax, edx
    ret
