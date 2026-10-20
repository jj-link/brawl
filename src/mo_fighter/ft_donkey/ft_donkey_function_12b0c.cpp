#include <types.h>
#pragma force_active on

union DonkeyInputPair {
    struct {
        u32 first;
        u32 second;
    } words;
    u64 packed;
};

extern "C" u64 fn_92_12B0C(void*) {
    DonkeyInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
