#include <types.h>
#pragma force_active on

extern "C" void* fn_27_307410(u8* p1, u32 p2, s32 p3) {
    s32 idx = p3 - *(s32*)(p1 + 0x18);
    return *(void**)(p1 + idx * 4 + 0x40);
}
