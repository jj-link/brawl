#include <types.h>
#pragma force_active on

extern "C" bool fn_8015911C(void* self, u32 bit, u32 kind) {
    if (kind == 0) {
        return 0;
    }
    if (kind == 1) {
        u32* base = *(u32**)((char*)self + 0);
        u32 v = *(u32*)((char*)base + ((bit >> 3) & 0x1FFFFFFC)) & (1u << (bit & 31));
        return v != 0;
    }
    if (kind == 2) {
        u32* base = *(u32**)((char*)self + 4);
        u32 v = *(u32*)((char*)base + ((bit >> 3) & 0x1FFFFFFC)) & (1u << (bit & 31));
        return v != 0;
    }
    return 0;
}
