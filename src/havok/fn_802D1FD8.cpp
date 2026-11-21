#pragma force_active on
#include <types.h>

extern "C" void fn_802D1FD8(char* arg0, u16* src, s32 count, char* dst) {
    count--;
    while (count-- >= 0) {
        s32 idx = *src++;
        char* p = *(char**)(arg0 + 0x30) + (idx >> 2) * 0x30 + ((idx & 3) << 2);
        *(f32*)(dst + 0) = *(f32*)p;
        *(f32*)(dst + 4) = *(f32*)(p + 0x10);
        *(f32*)(dst + 8) = *(f32*)(p + 0x20);
        *(s32*)(dst + 12) = idx;
        dst += 0x10;
    }
}
