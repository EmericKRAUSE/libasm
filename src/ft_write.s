bits 64

section .text
global ft_write
extern __errno_location

;rdi = fd
;rsi = buf
;rdx = number of bytes to write starting to buf

ft_write:
    mov rax, 1
    syscall

    cmp rax, 0
    js .error

    ret

.error:
    neg rax
    mov r8, rax
    call __errno_location __plt
    mov [rax], r8d
    mov rax, -1
    ret
