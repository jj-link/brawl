#include <types.h>
#pragma force_active on

extern "C" s32 fn_110_9CC8();

extern "C" s32 fn_110_1FBD8(s32 a, void* unused, s32 b, s32 c) {
    s32 idx = fn_110_9CC8() * 32;
    s32 addr = (a - 0x10000) + idx;
    addr = addr + b * 4;
    s32* table = *(s32**)(addr - 0x7600);
    return table[c];
}
