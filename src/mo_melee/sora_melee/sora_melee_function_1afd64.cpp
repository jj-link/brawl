#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AFD64(void* self, s32 idx) {
    s32 v = *(s32*)((char*)self + 8);
    s32 i = (v >> 22) + idx;
    if (i >= 0x125) {
        i -= 0x125;
    }
    return (char*)self + (i << 2) + 0xc;
}
