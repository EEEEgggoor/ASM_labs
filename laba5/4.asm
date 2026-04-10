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
    push rbp
    mov rbp, rsp
    
    vmovss xmm0, [x]           
    vmovss xmm1, [minus_three]
    vcomiss xmm0, xmm1         

    seta al                    
    movzx eax, al
    mov [z], eax
    
    mov esi, [z]
    lea rdi, [fmt]
    xor eax, eax
    call printf
    
    pop rbp
    xor eax, eax
    ret