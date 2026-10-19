#include <types.h>
#pragma force_active on

extern "C" s32 fn_107_C998();

extern "C" float fn_107_C940(u8* base, void* unused, s32 a, s32 b) {
    s32 n = fn_107_C998();
    u8* p = base + n * 100;
    float** tbl = (float**)(p - 0x3e70);
    float* arr = tbl[a];
    return arr[b];
}
