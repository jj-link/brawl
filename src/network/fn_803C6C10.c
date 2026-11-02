#include <types.h>
#pragma force_active on

extern u32 lbl_805A1210;
extern u32 lbl_805A1220;

s32 fn_803C6C10(u32 arg0, u32 arg1) {
    u32 *p;
    u32 *q;

    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0) {
        p = (u32*)((u8*)lbl_805A1220 + arg0 * 0x140);
    } else {
        p = 0;
    }

    if (p == 0 || p[2] == 0 || (q = (u32*)p[0]) == 0) {
        return 0xB003;
    }

    if (arg1 <= 1) {
        q[3] = arg1;
        return 0;
    }
    return -1;
}
