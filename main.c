#include <stdio.h>
#include <stdlib.h>
#include "context.h"

// The function we want to switch to
void fibre_function() {
    printf("Successfully jumped into the Fibre function!\n");
    printf("Day 1 goal reached. Exiting...\n");
    exit(0); 
}

struct context main_ctx;
struct context fibre_ctx;
char fibre_stack[4096]; // 4KB of memory for the new task's stack

int main() {
    printf("Starting the Kernel Shell Project...\n");

    // 1. Setup the new stack
    // Point to the end of the array because stacks grow DOWNWARDS
    uint64_t *rsp = (uint64_t *)&fibre_stack[4096];
    
    // 2. "Push" the function address onto the stack
    // This mimics what happens when a function is called
    *(--rsp) = (uint64_t)fibre_function;

    // 3. Set the context's stack pointer to our manually crafted stack
    fibre_ctx.rsp = (uint64_t)rsp;

    printf("About to switch context...\n");
    
    // Call our Assembly function
    extern void context_switch(struct context*, struct context*);
    context_switch(&main_ctx, &fibre_ctx);

    return 0;
}