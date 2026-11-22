#include <types.h>
#pragma force_active on

struct FlagByte { u8 b7:1; u8 b6:1; u8 b5:1; u8 b4:1; u8 b3:1; u8 b2:1; u8 b1:1; u8 b0:1; };
struct ByteLow { u8 upper : 7; u8 lower : 1; };
struct RuleByte { u8 rule : 3; u8 count : 3; u8 bit1 : 1; u8 bit0 : 1; };
struct GGData {
    char pad0[8];
    u8 f8 : 6;
    u8 f8b : 2;
    u8 f9 : 3;
    u8 count : 3;
    u8 f9b : 2;
    u8 fa0 : 1;
    u8 fa1 : 1;
    u8 fa2 : 1;
    u8 fa3 : 1;
    u8 fa4 : 4;
    u8 fb;
    u8 fc : 1;
    u8 fc1 : 7;
    char padd[0x13 - 0xd];
    u8 f13;
    char pad14[2];
    u8 f16;
    u8 pad17;
    u8 f18;
    u8 pad19;
    u16 f1a;
    char f1c[4];
    int f20;
    char pad24[0xc];
    int f30;
    int f34;
    int f38;
    int f3c;
    char pad40[0x1c];
    char f5c[4];
    u8 f60;
    u8 f61;
    u8 pad62;
    u8 f63;
    u8 f64;
    char pad65[3];
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
};

extern "C" s16 fn_800516F0(void);
extern "C" void fn_8010F960(u16, void*, void*, int);
extern void* lbl_1_bss_1998[];
extern void* g_GameGlobal;

extern "C" void fn_1_28894(void* arg0) {
    u32 zero = 0;
    u8* a = (u8*)arg0;
    u8* r31 = *(u8**)((u8*)g_GameGlobal + 0x8);
    u8* r30 = *(u8**)((u8*)g_GameGlobal + 0x3c);

    u8 t = r30[0x1c] + r30[0x3];
    r30[0x1c] = t;
    r30[0x1d] = (s8)(r30[0x1] - t);
    r30[0x5] |= 0x80;
    r30[0x1f] = (u8)*(s32*)(a + 0x14);

    s16 v;
    if (*(s32*)(a + 0x14) % 3 == 0) {
        v = fn_800516F0();
    } else {
        v = 0;
    }
    *(s16*)(r30 + 0x20) = v;

    ((GGData*)r31)->f8 = 5;
    RuleByte bits = *(RuleByte*)(r31 + 9);
    FlagByte flags = *(FlagByte*)(r31 + 0xa);
    bits.bit1 = 0;
    bits.bit0 = 1;
    flags.b7 = 1;
    flags.b5 = 1;
    flags.b4 = 1;
    flags.b1 = 1;
    *(RuleByte*)(r31 + 9) = bits;
    *(FlagByte*)(r31 + 0xa) = flags;
    r31[0xb] |= 0x8;
    ((ByteLow*)(r31 + 0xc))->lower = 0;
    r31[0xf] = (r31[0xf] & ~0x4) | 0x8;
    r31[0x14] = 4;
    r31[0x16] = 0;
    *(u32*)(r31 + 0x34) = zero;
    *(u32*)(r31 + 0x30) = zero;
    *(u32*)(r31 + 0x38) = zero;
    *(u32*)(r31 + 0x3c) = zero;
    *(u16*)(r31 + 0x1a) = 0x36;
    bits.count = *(s32*)(a + 0x18);
    *(RuleByte*)(r31 + 9) = bits;
    r31[0x18] = 0x20;

    u8* r9 = r31;
    s32 i = 0;
    for (; i < *(s32*)(a + 0x18); r9 += 0x5c, i++) {
        r9[0xa1] = 1;
    }

    for (s32 n = *(s32*)(a + 0x18); n < 4; ++n) {
        r31[n * 0x5c + 0x99] = 3;
    }

    u8* tbl = (u8*)lbl_1_bss_1998 + (*(s32*)(a + 0x18) - 1) * 0x4c;
    char* e = *(char**)(tbl + *(s32*)(a + 0x14) * 4);
    u8 idx = 0;
    if (e[0x14] != 0x3e) {
        idx = 1;
        if (e[0x64] != 0x3e) {
            idx = 2;
            if (e[0xb4] != 0x3e) {
                idx = 3;
                if (e[0x104] != 0x3e) {
                    idx = 4;
                    if (e[0x154] != 0x3e) idx = 5;
                }
            }
        }
    }
    r30[0x3] = idx;

    r31[0xa0] = 0;
    r31[0xfc] = 1;
    r31[0x158] = 2;
    r31[0x1b4] = 3;
    fn_8010F960(*(u16*)(r31 + 0x1a), r31 + 0x1c, r31 + 0x5c, 0);
}
