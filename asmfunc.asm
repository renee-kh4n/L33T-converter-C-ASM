;KHAN, Renee Althea F. | 19/12/2024
;%include "io64.inc"
section .data
original    db 'a','e','i','o','u','A','E','I','O','U', 0
replacement db '4','3','!','0','v','4','3', '!','0','v'
;var times 1000 db 0

section .text
bits 64      ;important
default rel  ; important

global asmfunc

asmfunc:
    ;GET_STRING [var], 1000

    ;PRINT_STRING "---------------ASM function---------------"
    ;PRINT_STRING "original string: "
    ;PRINT_STRING [cl] ; cl param for character
    ;NEWLINE
    
    mov r12b, byte [rcx]
    lea r8, [original]
    lea rbx, [replacement]
        
convert:
    cmp r12b, 0
    je done
    
    mov al, r12b  

loop_dict:
    cmp byte [r8], 0 
    je next
    
    mov rdx, [r8]

    cmp al, dl
    je replace
        
    inc r8
    inc rbx
    
    jmp loop_dict
    
replace:
    mov al, [rbx] 
    mov r12b, al
    
next: 
    mov r12b, byte [rcx + 1]
    
    lea r8, [original]
    lea bx, [replacement]
    
    jmp convert
        
done:
    ;NEWLINE
    ;PRINT_STRING "leet string: "
    ;PRINT_STRING [var]
    xor rax, rax
    ret

    ; print strings do not work here