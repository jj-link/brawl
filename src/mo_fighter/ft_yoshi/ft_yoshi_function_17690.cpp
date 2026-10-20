#include <types.h>
#pragma force_active on

// Returns an eight-byte input value (r3/r4 pair) that is zeroed on the stack.
extern "C" u64 fn_95_17690() {
    union {
        struct { u32 lo, hi; } words;
        u64 packed;
    } result;
    result.words.lo = 0;
    result.words.hi = 0;
    return result.packed;
}
