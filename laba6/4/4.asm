section .text
    global asm_syst

asm_syst:
    push rbp
    mov rbp, rsp
    sub rsp, 32         ; Выравнивание стека для Windows

    ; rcx = &x, rdx = &y, r8 = &z, r9 = &w
    mov ax, word [rcx]  ; ax = x
    mov cx, word [rdx]  ; cx = y
    
    sub cx, 1           ; cx = y - 1 (делитель)
    

    xor dx, dx       
    div cx  

    ; Сохраняем результаты
    mov word [r8], ax  
    mov word [r9], dx  

    add rsp, 32
    pop rbp
    ret