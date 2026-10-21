#include <types.h>
#pragma force_active on

extern "C" {
void* fn_801970EC(u8* p);
}

extern "C" s32 fn_8019D59C(u8* self) {
    u8* inner = (u8*)fn_801970EC(self + 0x20);
    if (inner != 0) {
        return *(s32*)(inner + 0x14);
    }
    return -1;
}
