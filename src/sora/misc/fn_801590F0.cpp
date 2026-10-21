#include <types.h>
#pragma force_active on

extern "C" bool fn_801590F0(void* self, u32 bit) {
    u32* base = *(u32**)((char*)self + 4);
    u32 v = *(u32*)((char*)base + ((bit >> 3) & 0x1FFFFFFC)) & (1u << (bit & 31));
    return v != 0;
}
