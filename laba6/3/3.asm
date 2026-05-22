section .text
    global calc_asm

calc_asm:
    push rbp
    mov rbp, rsp
    sub rsp, 32

    mov ax, word [rcx]     ; ax = x
    mov cx, word [rdx]     ; cx = y

    ; Вычисляем y^2
    mov dx, cx      
    imul dx, cx            ; dx = y * y

    ; z = 12 - x - y^2
    mov r10w, 12
    sub r10w, ax
    sub r10w, dx


    mov word [r8], r10w

    ; Эпилог функции
    add rsp, 32
    mov rsp, rbp
    pop rbp
    ret