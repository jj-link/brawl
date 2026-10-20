#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1E6F10(void* p, s32 n) {
    s32 v = *(s32*)((char*)p + 0x18) >> 28;
    s32 i = v + n;
    if (i >= 7) {
        i -= 7;
    }
    return (char*)p + i * 12 + 0x1c;
}
