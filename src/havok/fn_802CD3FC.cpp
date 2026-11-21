#pragma force_active on
#include <types.h>

extern "C" void fn_802CD3FC(u32* self, u32 maskA, u32 maskB) {
    int shift = 0;
    for (int i = 0; i < 32; i++) {
        u32 bit = 1u << shift;
        if (bit & maskA)
            self[7] |= maskB;
        if (bit & maskB)
            self[7] |= maskA;
        self++;
        shift++;
    }
}
