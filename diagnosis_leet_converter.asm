%include "io64.inc"
section .data
original_low db 'a','e','i','o','u', 0
original_up db 'A','E','I','O','U', 0
replacement db '4','3','!','0','v'
var times 1000 db 0

section .text
global main
main:
    ;write your code here
    GET_STRING [var], 1000
    lea rsi, [var]
    lea r8, [original_low]
    lea r9, [original_up]
    lea rbx, [replacement]
    
    PRINT_STRING "main"
    NEWLINE
    
convert:
    PRINT_STRING "convert"
    NEWLINE
    cmp byte [rsi], 0
    je done
    
    mov rax, [rsi]
    PRINT_STRING "Curr rsi: "
    PRINT_CHAR rax
    NEWLINE
    

loop_dict:
    PRINT_STRING "loop_dict"
    NEWLINE
    PRINT_CHAR [r8]
    NEWLINE
    cmp byte [r8], 0 
    je next
    
    mov rdx, [r8]
    mov rcx, [r9]

    PRINT_CHAR rax
    PRINT_STRING " : "
    PRINT_CHAR rdx
    NEWLINE
    cmp al, dl ; cmp rax, rdx doesnt work
    je replace
    
    cmp al, cl ; cmp rax, rdx doesnt work
    je replace
    
    inc r8
    inc r9
    inc rbx
    
    jmp loop_dict
    
replace:
    PRINT_STRING "replace"
    NEWLINE
    ;PRINT_CHAR [rbx]
    ;mov al, [rbx] ;causes runtime error when lea bx
    ;mov [rsi], al
    mov al, [rbx] ; Load the replacement character (1 byte)
    mov [rsi], al ; Replace the character in the input string
    
    ;jmp done

next: 
    PRINT_STRING "next"
    NEWLINE
    PRINT_CHAR [rsi]
    NEWLINE
    inc rsi
    
    lea r8, [original_low]
    lea r9, [original_up]
    lea bx, [replacement]
    
    jmp convert
        
done:
    PRINT_STRING "done"
    NEWLINE
    PRINT_STRING [var]
    NEWLINE
    PRINT_STRING "done"
    xor rax, rax
    ret