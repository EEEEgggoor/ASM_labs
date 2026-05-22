; rdi = pM  (указатель на матрицу)
; rsi = R   (количество строк)
; rdx = C   (количество столбцов)
; rcx = j   (номер столбца для замены)

section .text
    default rel
    global mre

mre:
    push rbp
    mov rbp, rsp
    
    ; Проверка на корректность j (0 <= j < C)
    cmp rcx, rdx        ; сравниваем j с C
    jae done            ; если j >= C, выходим (ничего не делаем)
    
    cmp rsi, 0          ; проверяем R > 0
    je done             ; если R == 0, выходим
    
    ; Сохраняем регистры
    push rbx
    push r12
    
    ; rbx = смещение до столбца j в байтах
    mov rbx, rcx        ; rbx = j
    shl rbx, 2          ; rbx = j * 4 (int = 4 байта)
    
    ; r12 = смещение до следующей строки в байтах (stride)
    mov r12, rdx        ; r12 = C
    shl r12, 2          ; r12 = C * 4
    
    ; rax = текущий указатель на M[0][j]
    mov rax, rdi        ; rax = pM
    add rax, rbx        ; rax = pM + j*4 (адрес M[0][j])
    
    ; rcx = счётчик строк (i = 0)
    xor rcx, rcx        ; rcx = 0
    
loop_start:
    cmp rcx, rsi        ; сравниваем i с R
    jge loop_end        ; если i >= R, выходим
    
    ; Записываем -1 в текущий элемент
    mov dword [rax], -1 ; M[i][j] = -1
    
    ; Переходим к следующей строке: M[i+1][j]
    add rax, r12        ; rax += C * 4 (переход на следующую строку, тот же столбец)
    
    inc rcx             ; i++
    jmp loop_start
    
loop_end:
    ; Восстанавливаем регистры
    pop r12
    pop rbx
    
done:
    pop rbp
    ret