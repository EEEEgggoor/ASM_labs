extern puts
global main

section .data
    group_info db "Группа: ПИН-25", 0
    number_info db "Номер: 1", 0
    team_info db "Состав команды: Лыгач Георгий, Холин Дмитрий, Мазурова Ольга", 0

section .text
main:
    push rbp
    mov rbp, rsp

    
    mov rdi, group_info   
    call puts           
    
    mov rdi, number_info
    call puts
    
    mov rdi, team_info
    call puts
    
    mov rsp, rbp
    pop rbp
    
    xor eax, eax
    ret