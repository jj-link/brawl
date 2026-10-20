#include <types.h>
#pragma force_active on

extern "C" void* fn_27_3BAA98(u8* self, u32 p2, u32 idx) {
    s32 base = *(s32*)(self + 0x18);
    return *(void**)(self + 0x2c + (idx - base) * 4);
}
