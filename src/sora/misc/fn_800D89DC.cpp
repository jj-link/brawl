#include <types.h>
#pragma force_active on

extern "C" u8 fn_800C8548(void);
extern "C" u8 fn_800C851C(void);
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80459884[];
extern char lbl_804598C0[];

extern "C" s32 fn_800D89DC(s32 arg0, u8* arg1) {
    u8 idx;
    s32 ret;
    s32 p;
    u8 b;

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
        p = arg0 + idx * 0x218 + 0x70;
    }
    b = ((u8*)p)[0x10f];
    ret = p + 0x120;
    netReport__FPCce(lbl_80459884, p,
                     *(u32*)(ret), *(u32*)(ret + 4),
                     *(u32*)(ret + 8), *(u32*)(ret + 12));
    netReport__FPCce(lbl_804598C0, (s8)b);
    *arg1 = b;
    return ret;
}
