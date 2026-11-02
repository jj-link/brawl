#include <types.h>
#pragma force_active on

extern s32 fn_8033891C(void);
extern s32 fn_803517BC(s32, s32);
extern void *lbl_805A0F70;

s32 fn_80337248(s32 arg0) {
    s32 off;
    s32 base;
    s32 i;
    s32 val;

    if (lbl_805A0F70 == 0 || arg0 == 0) {
        return -1;
    }
    for (i = 0, off = 0; i < *(s32 *)((u8 *)lbl_805A0F70 + 0x18); off += 0xC, i++) {
        base = *(s32 *)((u8 *)lbl_805A0F70 + 0x1C);
        if (base == 0) {
            val = 0;
        } else {
            val = fn_803517BC(fn_8033891C(), base + off);
            if (val == 0) {
                goto zero;
            }
            if (val != -1) {
                goto skip;
            }
        zero:
            val = 0;
        skip:;
        }
        if (arg0 == val) {
            return i;
        }
    }
    return -1;
}
