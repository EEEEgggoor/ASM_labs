section .data
    fmt db "%d ", 0
    newline db 10, 0

section .text
    default rel
    global print_mas
    extern printf

print_mas:
    sub rsp, 40
    push rbx
    push rsi

    mov rbx, rsi
    xor rcx, rcx
    mov rsi, 2

loop_start:
    cmp rcx, rbx
    jge loop_end

    mov r12, rcx
    mov r13, rsi

    lea rcx, [fmt]
    mov rdx, r13
    xor eax, eax
    call printf

    mov rcx, r12
    mov rsi, r13
    add rsi, 3
    inc rcx
    jmp loop_start

loop_end:
    lea rcx, [newline]
    xor eax, eax
    call printf

    pop rsi
    pop rbx
    add rsp, 40
    ret