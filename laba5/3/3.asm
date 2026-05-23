section .data
    x dd 55
    z dd 0
    fmt db "z = %d", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    sub rsp, 40

    mov eax, [x]
    cmp eax, -3
    setg al
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