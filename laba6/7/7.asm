section .text
    extern malloc
    global mmul

mmul:
    push rbp
    mov rbp, rsp
    push rbx
    push rsi
    push rdi
    sub rsp, 40     


    mov [rbp-8], rcx   ; pM1
    mov [rbp-16], rdx  ; R1
    mov [rbp-24], r8   ; C1
    mov [rbp-32], r9   ; pM2
    ; [rbp+48] = R2, [rbp+56] = C2

    ; C1 == R2
    cmp r8, [rbp+48]
    jne .error

    ; Выделение памяти: R1 * C2 * 4
    mov rax, rdx
    mul qword [rbp+56]
    shl rax, 2
    mov rcx, rax
    call malloc
    test rax, rax
    jz .error
    mov [rbp-40], rax  ; Адрес результата

    ; Вложенные циклы
    xor rsi, rsi       ; i = 0
.loop_i:
    xor rdi, rdi       ; j = 0
.loop_j:
    xor rbx, rbx       ; k = 0
    xor r10, r10       ; sum = 0
.loop_k:
    ; M1[i*C1 + k]
    mov rax, rsi
    imul rax, [rbp-24] ; i * C1
    add rax, rbx
    mov r11, [rbp-8]
    mov r11d, [r11 + rax*4]

    ; M2[k*C2 + j]
    mov rax, rbx
    imul rax, [rbp+56] ; k * C2
    add rax, rdi
    mov r12, [rbp-32]
    imul r11d, [r12 + rax*4]

    add r10d, r11d
    inc rbx
    cmp rbx, [rbp-24]  ; k < C1
    jl .loop_k

    ; Запись результата
    mov rax, rsi
    imul rax, [rbp+56] ; i * C2
    add rax, rdi
    mov r11, [rbp-40]
    mov [r11 + rax*4], r10d

    inc rdi
    cmp rdi, [rbp+56]  ; j < C2
    jl .loop_j

    inc rsi
    cmp rsi, [rbp-16]  ; i < R1
    jl .loop_i

    mov rax, [rbp-40]
    jmp .done

.error:
    xor rax, rax
.done:
    add rsp, 40
    pop rdi
    pop rsi
    pop rbx
    pop rbp
    ret