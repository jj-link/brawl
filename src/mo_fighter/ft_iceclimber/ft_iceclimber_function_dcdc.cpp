#include <types.h>
#pragma force_active on

extern "C" void fn_105_DCDC(void* work, u32 mask, u32 index) {
    u32* flags = *(u32**)((u8*)work + 0x1c);
    flags[index] |= mask;
}
