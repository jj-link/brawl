#include <types.h>
#pragma force_active on

extern "C" s32 fn_110_9CC8();

extern "C" float fn_110_9C70(char* base, s32 unused, s32 elem, s32 index) {
    char* p = base + fn_110_9CC8() * 0x68;
    float* table = *(float**)(p + elem * 4 - 0x3E70);
    return table[index];
}
