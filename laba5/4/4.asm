section .data
    x dq -4.0
    minus_three dq -3.0
    z dd 0
    fmt db "z = %d", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    sub rsp, 40

    vmovsd xmm0, [x]
    vmovsd xmm1, [minus_three]
    vcomisd xmm0, xmm1

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