#include <types.h>
#pragma force_active on

extern "C" s32 fn_2_36D28(u8* base, s32 a, s32 b) {
    base += a * 0x190;
    base += b << 2;
    return *(s32*)(base + 0x8c);
}
