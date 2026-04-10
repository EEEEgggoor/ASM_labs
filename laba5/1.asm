section .data
    x dd 5
    y dd -5
    w dd 0
    fmt db "w = %d", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    mov eax, [x]
    add eax, [y]
    
    sete al
    movzx eax, al
    
    mov [w], eax
    

    mov esi, [w]
    lea rdi, [fmt]
    xor eax, eax
    call printf
    
    xor eax, eax 
    ret