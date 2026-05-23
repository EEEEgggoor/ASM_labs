section .data
    x dd 5
    y dd -5
    w dd 0
    fmt db "w = %d", 10, 0

section .text
    default rel
    global main
    extern printf
    extern exit

main:
    sub rsp, 40        

    mov eax, [x]
    add eax, [y]
    
    sete al            
    movzx eax, al
    
    mov [w], eax

    lea rcx, [fmt]       
    mov edx, [w]      
    xor eax, eax       
    call printf

    extern getchar
    call getchar
    
    xor eax, eax     
    add rsp, 40        
    ret