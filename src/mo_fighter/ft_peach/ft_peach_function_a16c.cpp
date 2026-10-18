#include <types.h>
#pragma force_active on

extern "C" void fn_103_A16C(void* self, u32 mask, s32 index) {
    u32* flags = *(u32**)((char*)self + 0x1c);
    flags[index] |= mask;
}
