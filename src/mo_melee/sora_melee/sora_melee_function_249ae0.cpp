#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_249AE0(u8* self, s32 idx) {
    if (*(u8*)(self + 0x74)) {
        return;
    }
    if (idx >= *(s32*)(self + 0x104)) {
        return;
    }
    u8* p = self + idx * 4;
    *(s32*)(p + 0x124) = *(s32*)(self + 0xE4);
    *(s32*)(p + 0x108) = 0;
}
}
