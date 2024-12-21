; KHAN, Renee Althea F. | 19/12/2024
section .data
original    db 'a','e','i','o','u','A','E','I','O','U', 0
replacement db '4','3','!','0','v','4','3', '!','0','v'


section .text
bits 64 ;asmfunc.asm:8: error: parser: instruction expected
default rel 

global asmfunc
asmfunc:

    lea r8, [original]
    lea rbx, [replacement]
    mov al, cl   

loop_dict:
    cmp byte [r8], 0 
    je done
    
    mov rdx, [r8]

    cmp al, dl
    je replace
        
    inc r8
    inc rbx
    
    jmp loop_dict
    
replace:
    mov al, [rbx] 

        
done:
    ;xor rax, rax
    ret