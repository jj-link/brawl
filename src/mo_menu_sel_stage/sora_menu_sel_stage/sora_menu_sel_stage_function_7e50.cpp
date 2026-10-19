#include <types.h>
#pragma force_active on

extern "C" void fn_11_7E50(u8* base, s32 idx) {
    s32* p = (s32*)(base + idx * 0x58);
    if (*(s32*)((u8*)p + 0x70) == 2) {
        *(s32*)((u8*)p + 0x70) = 5;
    } else {
        *(s32*)((u8*)p + 0x70) = 0;
    }
}
