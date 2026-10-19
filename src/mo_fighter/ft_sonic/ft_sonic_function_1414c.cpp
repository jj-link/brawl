#include <stddef.h>
#pragma force_active on

typedef unsigned int  u32;
typedef unsigned long long u64;

// Eight-byte input values are returned in the r3/r4 register pair.
union SonicInputPair {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_123_1414C(void*) {
    SonicInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
