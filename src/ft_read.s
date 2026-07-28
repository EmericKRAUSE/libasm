bits 64

section .text
global ft_read
extern __errno_location

;rdi = fd
;rsi = buf
;rdx = count

ft_read:
    mov rax, 0
    syscall

    cmp rax, 0
    js .error

    ret

.error:
    neg rax
    mov r8 , rax

    call __errno_location wrt ..plt

    mov [rax], r8d
    mov rax, -1

    ret
