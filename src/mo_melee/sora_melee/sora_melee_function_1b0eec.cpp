#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1B0EEC(void* self, s32 idx) {
    s32 flags = *(s32*)((char*)self + 0x8);
    s32 n = flags >> 28;
    s32 i = n + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (char*)self + i * 4 + 0xc;
}
