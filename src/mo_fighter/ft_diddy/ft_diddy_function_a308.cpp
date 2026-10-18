#include <types.h>
#pragma force_active on

extern "C" void fn_115_A308(u8* work, u32 mask, u32 index) {
    u32* flags = *(u32**)(work + 0x1c);
    flags[index] &= ~mask;
}
