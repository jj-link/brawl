#include <types.h>
#pragma force_active on

extern char lbl_8048B600[];

void fn_80335638(s32, const char *, ...);
s32 fn_80343910(s8 *, const u8 *, s32);
void fn_803439D4(u8, s32, s32, s32, s8 *, s32);
u8 fn_8034E088(s8, s8);

void fn_80341148(s32 unused, s32 arg1, u8 *arg2) {
    s8 sp8[8][2];
    s8 sp18[128][4];
    s32 off;
    s32 i;
    s32 j;

    fn_80335638(0x40, lbl_8048B600, *arg2, arg1);
    for (i = 0; i < 128; i++) {
        if (fn_80343910(&sp8[0][0], arg2 + 1, i) == -1) {
            break;
        }
        j = 0;
        off = 0;
        for (; j < 4; j++) {
            s8 *p = (s8 *)((u32)&sp8[0][0] + (u32)off);
            sp18[i][j] = fn_8034E088(p[0], p[1]);
            off += 2;
        }
    }
    fn_803439D4(*arg2, arg1, 0, 0, &sp18[0][0], i);
}
