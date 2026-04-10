section .text
    default rel
    global fill_mass


fill_mass
    push rbp
    mov rbp, rsp


    mov eax, 2
    xor ecx, ecx

loop_start:
    cmp ecx, esi
    jge loop_end

    mov [rdi + rcx*4], eax

    add eax, 3
    inc ecx
    jmp loop_start

loop_end:
    pop rbp
    ret