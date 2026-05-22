section .data
    fmt db "%d ", 0
    newline db 10, 0

section .text
    default rel
    global print_mas
    extern printf

print_mas:
    push rbp
    mov rbp, rsp 
    push rbx

    mov rbx, rsi     
    xor ecx, ecx      
    mov eax, 2      

loop_start:
    cmp ecx, ebx       
    jge loop_end        

    push rcx
    push rax

    mov rsi, rax       
    lea rdi, [fmt]      
    xor eax, eax
    call printf
    
    pop rax      
    pop rcx

    add eax, 3      
    inc ecx          
    jmp loop_start

loop_end:
    lea rdi, [newline]
    xor eax, eax
    call printf

    pop rbx
    pop rbp
    ret