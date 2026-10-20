#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_318C0C(u8* p1, s32 unused, s32 p2) {
    s32 idx = p2 - *(s32*)(p1 + 0x18);
    return *(void**)(p1 + idx * 4 + 0xE8);
}
}
