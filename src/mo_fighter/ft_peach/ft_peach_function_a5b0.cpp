#include <types.h>
#pragma force_active on

extern "C" {
int fn_103_A5A4(void);

s32 fn_103_A5B0(u8* base, s32 unused, s32 i, s32 j) {
    s32 offset = fn_103_A5A4() * 0x18;
    u8* p = offset + (base - 0x10000);
    p += i * 4;
    s32* arr = *reinterpret_cast<s32**>(p - 0x75D0);
    return arr[j];
}
}
