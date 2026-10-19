#include <types.h>
#pragma force_active on

union WolfInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_125_10C28(void*) {
    WolfInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
