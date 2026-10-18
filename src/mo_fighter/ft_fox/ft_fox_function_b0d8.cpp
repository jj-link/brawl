#include <types.h>
#pragma force_active on

// The function performs:
// r3 = r3 + (r4 << 3) + 4
// This looks like indexing into an array of 8-byte elements (or pairs) where the base pointer is in r3 and index in r4.
// r3 = r3 + index * 8 + 4

// Looking at the assembly:
// slwi r0, r4, 3   -> r0 = r4 * 8
// add r3, r3, r0   -> r3 = r3 + r4 * 8
// addi r3, r3, 4   -> r3 = r3 + 4
// So it computes: r3 = r3 + r4 * 8 + 4

// This could be a helper to access a member at offset 4 within an 8-byte struct, indexed by r4.

struct Pair {
    u32 a;
    u32 b;
};

extern "C" u32* fn_97_B0D8(u32* base, int index) {
    // base + index * 8 bytes + 4 bytes
    // If we treat base as a pointer to Pair (8 bytes each), then we want &base[index].b or something at offset 4 within the index-th pair.
    // Let's define it generically with u32* and pointer arithmetic.
    // r3 + r4*8 + 4
    // If r3 points to the start of an array of 8-byte structs, and we want to get to offset 4 within element at index r4:
    // &((Pair*)r3)[r4].b  => r3 + r4*8 + 4

    Pair* pairs = (Pair*)base;
    return &pairs[index].b;
}
