#include <types.h>
#pragma force_active on

extern "C" void fn_125_B22C(u8* self, u32 mask, u32 index) {
    u32* flags = *(u32**)(self + 0x1c);
    flags[index] &= ~mask;
}
