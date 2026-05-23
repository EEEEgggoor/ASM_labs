section .text
    default rel
    global sa

sa:
    sub rsp, 40
    
    test rsi, rsi
    jz return_zero
    mov r10, 0x7FFFFFFFFFFFFFFF
    
    mov rcx, rsi
    xor rax, rax
    movsd xmm1, [rdi]
    

    movq rdx, xmm1
    and rdx, r10
    movq xmm2, rdx
    
    mov rdx, 1
    
loop_start:
    cmp rdx, rcx
    jge loop_end
    
    movsd xmm0, [rdi + rdx*8]
    
    movq r8, xmm0
    and r8, r10
    movq xmm3, r8
    
    comisd xmm3, xmm2
    jae not_closer
    
    movsd xmm1, xmm0
    movq xmm2, r8
    mov rax, rdx
    
not_closer:
    inc rdx
    jmp loop_start
    
loop_end:
    add rsp, 40
    ret

return_zero:
    xor rax, rax
    add rsp, 40
    ret