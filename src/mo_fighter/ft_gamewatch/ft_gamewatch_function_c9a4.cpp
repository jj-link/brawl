#include <types.h>
#pragma force_active on

extern "C" s32 fn_107_C998();

extern "C" s32 fn_107_C9A4(u8* a, s32 unused, s32 b, s32 c) {
    s32* arr = *(s32**)(a - 0x10000 + fn_107_C998() * 8 + b * 4 - 0x7628);
    return arr[c];
}
