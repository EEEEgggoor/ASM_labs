section .text
    default rel
    global sa

sa:
    sub rsp, 40
    
    ; Аргументы: RCX = arr, RDX = N, XMM0 = x (третий аргумент double)
    test rdx, rdx
    jz return_zero
    
    ; Вычисляем |arr[0] - x| и сохраняем как текущий минимум
    movsd xmm1, [rcx]     ; xmm1 = arr[0]
    subsd xmm1, xmm0      ; xmm1 = arr[0] - x
    
    ; Абсолютное значение: обнуляем старший бит (знаковый бит)
    mov r8, 0x7FFFFFFFFFFFFFFF
    movq xmm2, r8
    andpd xmm1, xmm2      ; xmm1 = |arr[0] - x| (текущий min_diff)
    
    xor rax, rax          ; rax = index_min = 0
    mov r9, 1             ; r9 = i = 1
    
loop_start:
    cmp r9, rdx           ; i < N
    jge loop_end
    
    ; Вычисляем |arr[i] - x|
    movsd xmm3, [rcx + r9*8]
    subsd xmm3, xmm0      ; xmm3 = arr[i] - x
    andpd xmm3, xmm2      ; xmm3 = |arr[i] - x|
    
    ; Сравниваем с минимумом
    comisd xmm3, xmm1
    jae not_closer        ; Если текущее >= min, пропускаем
    
    movsd xmm1, xmm3      ; Обновляем min_diff
    mov rax, r9           ; Обновляем index_min
    
not_closer:
    inc r9
    jmp loop_start
    
loop_end:
    add rsp, 40
    ret

return_zero:
    xor rax, rax
    add rsp, 40
    ret