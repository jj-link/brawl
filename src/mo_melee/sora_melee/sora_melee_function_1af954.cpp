#include <types.h>
#pragma force_active on

struct fn27Entry {
    u8 pad0[8];
    s32 m8;
};

extern "C" {
void* fn_27_1AF954(fn27Entry* p, s32 idx) {
    s32 sh = p->m8 >> 22;
    s32 n = sh + idx;
    if (n >= 0x11b) {
        n -= 0x11b;
    }
    return (char*)p + (n << 2) + 0xc;
}
}
