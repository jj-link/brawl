#include <types.h>
#pragma force_active on

extern "C" void fn_102_9174(void* work, u32 mask, u32 index) {
    u32* flags = *(u32**)((char*)work + 0x1c);
    flags[index] &= ~mask;
}
