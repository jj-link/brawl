#include <types.h>
#pragma force_active on

extern "C" s32 fn_123_A858();

extern "C" float fn_123_A800(u8* self, s32 unused, s32 a, s32 b) {
    u8* p = self + fn_123_A858() * 0x118;
    float* arr = *(float**)(p + a * 4 - 0x3E70);
    return arr[b];
}
