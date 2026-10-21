#include <types.h>
#pragma force_active on
extern "C" s32 fn_101_D7E4();

extern "C" s32 fn_101_D7F0(s32 base, s32 unused, s32 a, s32 b) {
    s32 t = fn_101_D7E4() * 0x28;
    s32 addr = (base - 0x10000) + t;
    addr = addr + a * 4;
    s32* row = *(s32**)(addr - 0x75D8);
    return row[b];
}
