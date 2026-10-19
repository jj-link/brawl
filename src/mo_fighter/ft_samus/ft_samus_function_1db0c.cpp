#include <types.h>
#pragma force_active on

// Returns a zeroed eight-byte value in the r3/r4 register pair.
union Fn94InputPair {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_94_1DB0C(void*) {
    Fn94InputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
