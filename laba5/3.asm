section .data
    x dd 55   
    z dd 0
    fmt db "z = %d", 10, 0

section .text
    default rel
    global main
    extern printf

main:
    mov eax, [x]
    cmp eax, -3
    setg al
    movzx eax, al
    mov [z], eax
    
    mov esi, [z]
    lea rdi, [fmt]
    xor eax, eax
    call printf
    
    xor eax, eax 
    ret
    