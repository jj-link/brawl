#include <types.h>
#pragma force_active on

union InputPair {
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_93_14820(void) {
    InputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
