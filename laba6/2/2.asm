section .text
    global ab16_asm
    extern printf16

ab16_asm:
    push rbp
    mov rbp, rsp
    
    ; Сохраняем rbx, в нем держим копию исходного x
    push rbx           
    
    sub rsp, 40        

    ; Читаем 16-битное значение по указателю из rcx
    movzx ebx, word [rcx]  

    ; 0. Печать исходного значения x
    mov [rsp + 32], bx    
    lea rcx, [rsp + 32]   
    call printf16

    ; 1. Умножение на 2 / Сдвиг влево
    mov ax, bx            
    shl ax, 1             ; Сдвиг влево на 1 бит (эквивалентно x * 2)
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    ; 2. Беззнаковое деление на 2
    mov ax, bx            
    shr ax, 1             ; Логический сдвиг вправо (заполнение нулями)
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    ; 3. Знаковое деление на 2
    mov ax, bx            
    sar ax, 1             ; Арифметический сдвиг (сохраняет знаковый старший бит)
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    ; 4. Остаток от деления на 16 (а5, б5)
    mov ax, bx            
    and ax, 15            ; Выделяем младшие 4 бита (x & 15)
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    ; 5. Округление вниз до кратного 16 (а6, б6)
    mov ax, bx            
    and ax, -16           ; Обнуляем младшие 4 бита (маска 0xFFF0)
    mov [rsp + 32], ax    
    lea rcx, [rsp + 32]   
    call printf16

    add rsp, 40        
    pop rbx            
    mov rsp, rbp
    pop rbp
    ret