#include <types.h>
#pragma force_active on

union ZeroInputPair {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_104_129BC(void*) {
    ZeroInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
