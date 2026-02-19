.text
.globl context_switch

# context_switch(struct context *old, struct context *new)
# rdi = address of old struct, rsi = address of new struct
context_switch:
    # 1. SAVE the current CPU state into the 'old' context
    movq %rsp, 56(%rdi)   # Save Stack Pointer to offset 56
    movq %rbp, 32(%rdi)   # Save Base Pointer to offset 32
    movq %rbx, 40(%rdi)   # Save RBX to offset 40

    # 2. LOAD the state from the 'new' context into the CPU
    movq 56(%rsi), %rsp   # Load New Stack Pointer from offset 56
    movq 32(%rsi), %rbp   # Load New Base Pointer from offset 32
    movq 40(%rsi), %rbx   # Load New RBX from offset 40

    # 3. JUMP to the new location
    ret                   # Pops the address from the top of the NEW stack and jumps there

.section .note.GNU-stack,"",@progbits