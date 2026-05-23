section .data
    x dd -15
    z dd 0
    fmt db "z = %u", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    sub rsp, 40

    mov eax, [x]
    cmp eax, -3
    seta al
    movzx eax, al
    mov [z], eax

    lea rcx, [fmt]
    mov edx, [z]
    xor eax, eax
    call printf

    extern getchar
    call getchar

    xor eax, eax
    add rsp, 40
    ret