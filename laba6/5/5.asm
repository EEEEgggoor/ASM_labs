section .text
    global calc_lea_asm


calc_lea_asm:
    lea rax, [rcx*2 + rcx + 7] ; z = 3x + 7
    mov [rdx], rax  
    ret