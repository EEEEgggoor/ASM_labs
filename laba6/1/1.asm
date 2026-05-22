section .rdata
    up_num   db " Up - ", 0
    down_num db " Down -", 0
    num      db " Num - ", 0

section .text
    global fc16_asm
    extern printf16
    extern printf

fc16_asm:
    push rbp
    mov rbp, rsp
    
    push rbx 
    
    sub rsp, 40        


    movzx ebx, word [rcx]  

    ; 1. Вывод исходного значения x
    mov rcx, num    
    call printf 

    mov [rsp + 32], bx    
    lea rcx, [rsp + 32]  
    call printf16

    ; 2. а) Округление вниз (x1 = x & 0xFFC0)
    mov rcx, down_num     
    call printf 

    mov ax, bx            
    and ax, 0xFFC0        
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    ; 3. б) Округление вверх (x2 = (x + 63) & 0xFFC0)
    mov rcx, up_num     
    call printf 

    mov ax, bx            
    add ax, 63            
    and ax, 0xFFC0        
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    ; Эпилог функции
    add rsp, 40        
    pop rbx            
    mov rsp, rbp
    pop rbp
    ret