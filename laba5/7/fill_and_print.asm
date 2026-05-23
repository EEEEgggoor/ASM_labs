section .data
    fmt db "%d ", 0       ; Формат вывода: число и пробел
    newline db 10, 0      ; Перенос строки

section .text
    default rel
    global print_mas      ; Функция принимает один аргумент: N (в rdx)
    extern printf

print_mas:
    sub rsp, 40           ; Резервируем Shadow Space
    push rbx              ; Сохраняем callee-saved регистры
    push rsi
    push r12              ; Используем r12 для хранения N

    mov r12, rdx          ; Сохраняем N в r12
    xor rsi, rsi          ; rsi будет счетчиком цикла (i = 0)
    mov rbx, 2            ; rbx будет текущим числом последовательности (начнем с 2)

loop_start:
    cmp rsi, r12          ; Сравниваем i с N
    jge loop_end          ; Если i >= N, конец


    lea rcx, [fmt]        ; Первый аргумент: форматная строка
    mov rdx, rbx          ; Второй аргумент: текущее число
    xor eax, eax         
    call printf


    add rbx, 3            ; Следующее число последовательности (+3)
    inc rsi               ; Увеличиваем индекс
    jmp loop_start

loop_end:
    lea rcx, [newline]    ; Печатаем перенос строки
    xor eax, eax
    call printf

    pop r12               ; Восстанавливаем регистры
    pop rsi
    pop rbx
    add rsp, 40
    ret