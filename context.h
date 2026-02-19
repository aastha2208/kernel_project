#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdint.h>

// This struct holds the CPU state (registers) for a single fibre.
// Each member is 8 bytes (64-bit).
struct context 
{
    uint64_t r15; // Offset 0
    uint64_t r14; // Offset 8
    uint64_t r13; // Offset 16
    uint64_t r12; // Offset 24
    uint64_t rbp; // Offset 32 (Base Pointer)
    uint64_t rbx; // Offset 40
    uint64_t rip; // Offset 48 (Instruction Pointer)
    uint64_t rsp; // Offset 56 (Stack Pointer)
};

#endif