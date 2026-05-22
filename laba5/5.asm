section .data
    x dd 0
    z dd 0
    fmt db "z = %u", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    mov eax, [x]
    mov ecx, eax
    shl ecx, 2
    add ecx, eax

    mov edx, 32
    cmp ecx, 7
    cmovbe edx, ecx
    
    mov [z], edx
    

    mov esi, [z]
    lea rdi, [fmt]
    xor eax, eax
    call printf
    
    pop rbp
    xor eax, eax
    ret
