#include <types.h>
#pragma force_active on

// The eight-byte return value is carried in the r3/r4 register pair.
union ToonlinkInputPair {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_121_1486C(void*) {
    ToonlinkInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
