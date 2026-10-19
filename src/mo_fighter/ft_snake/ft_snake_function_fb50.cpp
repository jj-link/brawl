#include <types.h>
#pragma force_active on

extern "C" s32 fn_122_FB44();

extern "C" s32 fn_122_FB50(u8* base, s32, s32 element, s32 parameter) {
    u8* p = base - 0x10000 + fn_122_FB44() * 0x1c;
    p += element * 4;
    s32* table = *(s32**)(p - 0x7620);
    return table[parameter];
}
