global main
extern scanf
extern printf

section .data
    fmt_in  db "%hd %d %lld %f %lf", 0
    fmt_out db "i16=%hd i32=%d i64=%lld f32=%f f64=%f", 10, 0

section .text
main:
    push rbp
    mov rbp, rsp
    sub rsp, 32

    ; scanf
    mov rdi, fmt_in
    lea rsi, [rbp-2]
    lea rdx, [rbp-8]
    lea rcx, [rbp-16]
    lea r8,  [rbp-20]
    lea r9,  [rbp-32]
    xor eax, eax
    call scanf

    ; printf
    mov rdi, fmt_out
    movsx esi, word [rbp-2]
    mov edx, dword [rbp-8]
    mov rcx, qword [rbp-16]
    movss xmm0, dword [rbp-20]
    cvtss2sd xmm0, xmm0
    movsd xmm1, qword [rbp-32]

    mov eax, 2
    call printf

    xor eax, eax
    leave
    ret