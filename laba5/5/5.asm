section .data
    x dd 0
    z dd 0
    fmt db "z = %u", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    sub rsp, 40

    mov eax, [x]
    mov ecx, eax
    shl ecx, 2
    add ecx, eax

    mov edx, 32
    cmp ecx, 7
    cmovbe edx, ecx
    
    mov [z], edx

    mov r8d, [z]
    lea rcx, [fmt]
    mov edx, r8d
    xor eax, eax
    call printf

    extern getchar
    call getchar
    
    xor eax, eax
    add rsp, 40
    ret