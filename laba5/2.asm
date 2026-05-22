section .data
    x dd 4294967294   
    z dd 0
    fmt db "z = %u", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    mov eax, [x]
    cmp eax, -3
    seta al
    movzx eax, al
    mov [z], eax
    
    mov esi, [z]
    lea rdi, [fmt]
    xor eax, eax
    call printf
    
    xor eax, eax 
    ret
    