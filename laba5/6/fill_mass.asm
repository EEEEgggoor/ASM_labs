section .text
    default rel
    global fill_mass

fill_mass:
   
    mov r8, rcx       
    mov r9d, edx  
    
    mov eax, 2
    xor rcx, rcx      ; Теперь используем rcx как счетчик цикла

loop_start:
    cmp rcx, r9       ; Сравниваем счетчик с длиной N
    jge loop_end

    mov [r8 + rcx*4], eax ; Записываем значение в массив

    add eax, 3
    inc rcx
    jmp loop_start

loop_end:
    ret