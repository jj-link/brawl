#include <types.h>
#pragma force_active on

extern "C" s32 fn_115_A76C();

extern "C" s32 fn_115_A778(s32 base, s32 unused, s32 a, s32 b) {
    s32 t = fn_115_A76C() * 24;
    s32 addr = (base - 0x10000) + t;
    addr = addr + a * 4;
    s32* row = *(s32**)(addr - 0x7540);
    return row[b];
}
