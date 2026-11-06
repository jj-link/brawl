#include <types.h>
#pragma force_active on

extern "C" u8 fn_800C8548(void);
extern "C" u8 fn_800C851C(void);
extern "C" void fn_803F8C5C(int seed);
extern "C" void srandi__Fl(long);
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_804588C0[];
extern char lbl_80458904[];

extern "C" u32 fn_800D3AC4(s32 arg0) {
    u8 idx;
    s32 p;
    s32 base;
    u32 seed;

    idx = fn_800C8548();
    if (idx == 0xFF) {
        p = 0;
    } else {
        p = arg0 + idx * 0x218 + 0x70;
    }
    if (p == 0) {
        idx = fn_800C851C();
        if (idx == 0xFF) {
            idx = 4;
        }
        base = arg0 + idx * 0x218;
        p = base + 0x70;
        netReport__FPCce(lbl_804588C0, base);
    }
    seed = (((u8*)p)[0x130] << 24) + (((u8*)p)[0x131] << 16) + (((u8*)p)[0x132] << 8) + ((u8*)p)[0x133];
    fn_803F8C5C(seed);
    srandi__Fl(seed);
    netReport__FPCce(lbl_80458904, seed);
    return seed;
}
