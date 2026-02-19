#ifndef FIBRE_H
#define FIBRE_H

#include "context.h"
#include <stdint.h>

// Different states a fibre can be in
typedef enum {
    UNUSED,
    RUNNING,
    READY,
    FINISHED
} fibre_state;

struct fibre {
    int id;                 // Unique ID for the fibre
    fibre_state state;      // Current status
    struct context context; // Saved CPU registers (from Day 1)
    void *stack_bottom;     // Pointer to the start of the allocated stack
};

// Function prototypes (What the factory can do)
struct fibre* fibre_create(void (*func)(void));

#endif