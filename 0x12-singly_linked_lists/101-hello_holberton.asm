section .data
    format db "Hello, Holberton",10,0

section .text
    global main

extern printf
main:
    mov edi, format
    xor eax, eax
    call printf
    mov eax, 0
    ret
