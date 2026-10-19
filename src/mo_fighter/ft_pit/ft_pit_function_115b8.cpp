#include <types.h>
#pragma force_active on

union PairU64 {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_112_115B8(void*) {
    PairU64 result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
