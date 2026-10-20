#include <types.h>
#pragma force_active on

extern "C" void* fn_27_F83B8(void* self, s32 idx) {
    s32 v = *(s32*)((char*)self + 0x18);
    s32 t = v >> 26;
    s32 n = t + idx;
    n = (n >= 0x16) ? n - 0x16 : n;
    return (char*)self + n * 12 + 0x1c;
}
