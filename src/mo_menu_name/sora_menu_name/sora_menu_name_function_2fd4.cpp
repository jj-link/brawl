#include <types.h>
#pragma force_active on

extern "C" s32 fn_16_2FD4(void* self) {
    u8* base = (u8*)self;
    u16 b = *(u16*)(base + 0x1ee);
    u16 a = *(u16*)(base + 0x1ec);
    s16 v = *(s16*)(base + ((b + a) << 2) + 0x1f2);
    s32 r = (u16)(v + 2) > 1 ? v : -1;
    if (r == -1) {
        return -1;
    }
    return r;
}
