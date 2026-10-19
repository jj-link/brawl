#include <types.h>
#pragma force_active on

extern "C" s32 fn_102_95D8();

extern "C" float fn_102_9580(u8* base, void* unused, s32 a, s32 b) {
    s32 idx = fn_102_95D8();
    float** t = (float**)(base + idx * 0xbc - 0x3e70);
    return t[a][b];
}
