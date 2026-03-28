global f1
section .text

f1:
    lea eax, [ecx + edx]
    add eax, 12  
    ret