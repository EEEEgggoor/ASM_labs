global main
extern myfunc
extern printf

section .data
    fmt db "Result = %d", 10, 0

section .text

main:
    push rbp
    mov rbp, rsp


    mov rdi, 1    
    mov rsi, 2    
    mov rdx, 3    
    mov rcx, 4   
    mov r8,  5    
    mov r9,  6   

    sub rsp, 16    

    mov qword [rsp], 7        
    mov qword [rsp + 8], 8   

    call myfunc

    add rsp, 16

    mov rsi, rax
    mov rdi, fmt
    xor rax, rax
    call printf

    mov eax, 0
    leave
    ret