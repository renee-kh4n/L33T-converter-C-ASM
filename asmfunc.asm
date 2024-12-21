; KHAN, Renee Althea F. 

section .text
bits 64      ;important
default rel  ; important

global asmfunc

asmfunc:
        
    lea rsi, byte [rcx]
    lea r11, byte [rdx]
    lea rbx, byte [r8]
        
convert:
    cmp byte [rsi], 0
    je done
    
    mov rax, [rsi]    

loop_dict:
    cmp byte [r11], 0 
    je next
    
    mov rdx, [r11]

    cmp al, dl
    je replace
        
    add r11, 1
    add rbx, 1
    
    jmp loop_dict
    
replace:
    mov al, [rbx] 
    mov [rsi], al
    
next: 
    add rsi, 1
    
    lea r11, [original]
    lea bx, [replacement]
    
    jmp convert
        
done:
    NEWLINE
    PRINT_STRING "leet string: "
    PRINT_STRING [var]
    xor rax, rax
    ret

    ; prints and newline are not permitted