#include <types.h>
#pragma force_active on

typedef int (*FnTbl)(void*, u32, u32, u32);

extern u32 lbl_805A1210;
extern u32 lbl_805A1220;
extern FnTbl lbl_804927D0[4];

int fn_803C4DEC(u32 arg, u32 arg1, u32 arg2) {
    u32* p;
    u32 idx;

    if (arg < lbl_805A1210 && lbl_805A1220 != 0) {
        p = (u32*)((u8*)lbl_805A1220 + arg * 0x140);
    } else {
        p = 0;
    }

    if (p == 0 || (p = (u32*)*p) == 0) {
        return 0xB003;
    }

    idx = p[2];
    if (idx < 4) {
        FnTbl fn = lbl_804927D0[idx];
        if (fn != 0) {
            return fn(p, arg1, arg2, arg);
        }
        return 0;
    }

    return -1;
}
