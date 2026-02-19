#include <stdlib.h>
#include "fibre.h"

#define STACK_SIZE 4096

struct fibre* fibre_create(void (*func)(void)) {
    // 1. Allocate memory for the fibre structure
    struct fibre *f = (struct fibre*)malloc(sizeof(struct fibre));
    
    // 2. Allocate 4KB of memory for this fibre's private stack
    f->stack_bottom = malloc(STACK_SIZE);
    f->state = READY;
    f->id = 1; // For now, we'll just give it ID 1

    // 3. Setup the stack pointer (RSP)
    // Remember: Stacks grow DOWN, so start at the end of the memory
    uint64_t *rsp = (uint64_t *)((char *)f->stack_bottom + STACK_SIZE);

    // 4. "Push" the function address onto the stack
    // This is exactly what we did manually in main.c yesterday
    *(--rsp) = (uint64_t)func;

    // 5. Save this stack pointer into the fibre's context
    f->context.rsp = (uint64_t)rsp;

    return f;
}