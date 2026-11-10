#include <types.h>

typedef struct S {
    u8 pad[0x88];
    u32 f88;
} S;

#pragma force_active on

s32 fn_80251C1C(S *s, u32 arg1, u32 arg2) {
    u32 temp = arg2 ^ arg1;
    u32 r6 = 0;
    if (temp & 1) {
        r6 |= 0x10;
        if (arg2 & 1) {
            r6 |= 0x800;
        }
    }
    if (temp & 2) {
        r6 |= 0x8;
        if (arg2 & 2) {
            r6 |= 0x400;
        }
    }
    if (temp & 4) {
        r6 |= 0x100;
    }
    if (temp & 8) {
        r6 |= 0x20;
        if (arg2 & 8) {
            r6 |= 0x1000;
        }
    }
    return s->f88 & r6;
}
