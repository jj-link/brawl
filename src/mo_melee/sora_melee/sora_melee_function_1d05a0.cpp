#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1D05A0(void* p, s32 idx) {
    s32 v = *(s32*)((char*)p + 8);
    s32 i = (v >> 26) + idx;
    if (i >= 0x11) {
        i -= 0x11;
    }
    return (char*)p + i * 12 + 12;
}
