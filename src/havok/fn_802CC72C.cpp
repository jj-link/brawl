#include <types.h>
#pragma force_active on

#pragma use_lmw_stmw on
#pragma dont_inline on

extern "C" void fn_802CC72C(u8* self, s32 a, s32 b, s32 c) {
    s32 off;
    s32 i;
    i = 0;
    off = 0;

    u32* w = (u32*)self;
    w[a + 67] |= w[b + 67];

    while (i < *(s32*)(self + 0x1c1c)) {
        u8* entry = *(u8**)(self + 0x1c18) + off;
        s32 e = *(s32*)(entry + 4);
        if (e == a) {
            fn_802CC72C(self, *(s32*)entry, e, c + 1);
        }
        off += 8;
        i++;
    }
}
