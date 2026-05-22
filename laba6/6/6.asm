section .text
    global mce_si

mce_si:

    mov eax, 1       
    
    test rdx, rdx      
    jz .done           

.loop:
    imul eax, [rcx]     
    
    add rcx, 4          
    dec rdx 
    jnz .loop 

.done:
    ret