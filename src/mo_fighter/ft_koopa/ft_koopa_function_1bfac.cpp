#include <types.h>
#pragma force_active on

union ZeroPair {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_102_1BFAC(void*) {
    ZeroPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
