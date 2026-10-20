#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A5128(void* ptr) {
    u32* p = (u32*)((u8*)ptr + 8);
    *p |= 0x00010000;
}
