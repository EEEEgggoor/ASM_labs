section .text
    default rel
    global sa

sa:
    push rbp
    mov rbp, rsp
    
    test rsi, rsi
    jz return_zero
    mov r10, 0x7FFFFFFFFFFFFFFF
    
    mov rcx, rsi
    mov rax, 0
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
    movsd xmm2, xmm3             
    mov rax, rdx               
    
not_closer:
    inc rdx
    jmp loop_start
    
loop_end:
    pop rbp
    ret

return_zero:
    xor rax, rax
    pop rbp
    ret