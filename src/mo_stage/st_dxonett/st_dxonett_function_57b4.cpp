#include <types.h>
#pragma force_active on

extern "C" void* fn_78_57B4(void* self, int index) {
    s32 v = *(s32*)((u8*)self + 8);
    int i = (v >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return (u8*)self + i * 0x90 + 0xc;
}
