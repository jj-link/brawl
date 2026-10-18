#include <types.h>
#pragma force_active on

extern "C" void fn_113_CC60(void* self, u32 index) {
    u32** p = (u32**)((u8*)self + 0x1c);
    (*p)[index] = 0;
}
