#include <types.h>
#pragma force_active on

extern "C" void fn_105_DCB0(void* self, u32 mask, u32 index) {
    u32* flags = *(u32**)((char*)self + 0x1c);
    flags[index] &= ~mask;
}
