#include <stdlib.h>
#include <stdio.h>
#include "fibre.h"

// External assembly function from Day 1
extern void context_switch(struct context *old, struct context *new);

struct context main_ctx;

void task_one() {
    printf("Task 1: The factory successfully created me!\n");
    printf("Task 1: I am running on my own private stack.\n");
    // For now, we still exit here because we don't have a scheduler yet
    exit(0); 
}

int main() {
    printf("Starting Day 2: The Fibre Factory...\n");

    // Create a new fibre using our factory function
    struct fibre *my_fibre = fibre_create(task_one);

    printf("Switching to Task 1...\n");
    
    // Switch from Main to our new Fibre
    context_switch(&main_ctx, &my_fibre->context);

    return 0;
}