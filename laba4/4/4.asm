global main
extern scanf
extern printf

section .data
    prompt db "Введите i16, i32, i64, f32, f64: ", 0
    fmt_in  db "%hd %d %lld %f %lf", 0
    fmt_out db "i16=%hd i32=%d i64=%lld f32=%f f64=%lf", 10, 0

section .text
main:
    push rbp
    mov rbp, rsp
    sub rsp, 32              ; место под переменные

    ; расположение:
    ; [rbp-2]   i16 (short)
    ; [rbp-8]   i32 (int)
    ; [rbp-16]  i64 (long long)
    ; [rbp-20]  f32 (float)
    ; [rbp-32]  f64 (double)

    mov rdi, prompt
    xor eax, eax             ; нет float-аргументов
    call printf 

    ; --- scanf ---
    mov rdi, fmt_in
    lea rsi, [rbp-2]
    lea rdx, [rbp-8]
    lea rcx, [rbp-16]
    lea r8,  [rbp-20]
    lea r9,  [rbp-32]
    xor eax, eax            ; для varargs
    call scanf

    cmp eax, 5
    jne fail

    mov rdi, fmt_out
    movsx esi, word [rbp-2]
    mov edx, dword [rbp-8]
    mov rcx, qword [rbp-16]
    movss xmm0, dword [rbp-20]
    cvtss2sd xmm0, xmm0
    movsd xmm1, qword [rbp-32]
    mov eax, 2              ; количество XMM аргументов
    call printf

    xor eax, eax
    leave
    ret

fail:
    mov eax, 1
    leave
    ret