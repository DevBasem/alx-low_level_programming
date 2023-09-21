section .data
    format db "Hello, Holberton",10,0
    format_len equ $ - format

section .text
    global main

extern printf
main:
    sub     rsp, 8
    mov     rdi, format
    call    printf

    add     rsp, 8
    mov     rax, 60
    xor     rdi, rdi
    syscall
