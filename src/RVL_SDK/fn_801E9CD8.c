#include <types.h>
#pragma force_active on

extern unsigned char *lbl_805A0814;
extern unsigned char lbl_804DE640[0x58];

#define U16(p, n) (*(u16 *)((p) + (n)))

void fn_801E9CD8(s32 arg0, s32 arg1, u16 *arg2, s16 *arg3) {
    u16 count18, a;
    u8 b;
    u32 off, count, mode, dph, dpv;
    u8 *p = (u8 *)lbl_805A0814;

    dph = (u32)(arg0 - 1);
    dpv = (u32)(arg1 - 1);
    count = dpv * 2 + dph / U16(p, 0x1A);
    mode = *(u32 *)(lbl_804DE640 + 0x24);

    if (mode == 0) {
        count18 = U16(p, 0x18);
        if (count < count18) {
            b = p[0];
            a = U16(p, 4);
            off = (u32)b * 3;
            if (count < (u32)(a + (s32)off)) {
                *arg3 = -1;
            } else if (count >= (u32)(count18 - U16(p, 8))) {
                *arg3 = -1;
            } else {
                *arg3 = (s16)(((count - off) - a) & 0xFFFFFFFE);
            }
        } else {
            u16 a;
            count -= count18;
            b = p[0];
            a = U16(p, 6);
            off = (u32)b * 3;
            if (count < (u32)(a + (s32)off)) {
                *arg3 = -1;
            } else if (count >= (u32)(count18 - U16(p, 10))) {
                *arg3 = -1;
            } else {
                *arg3 = (((count - off) - a) & 0xFFFFFFFE) + 1;
            }
        }
    } else if (mode == 1) {
        count18 = U16(p, 0x18);
        if (count >= count18) {
            count -= count18;
        }
        {
            u8 *q = *(u8 **)(void *)&lbl_805A0814;
            b = q[0];
            a = U16(q, 4);
        }
        off = (u32)b * 3;
        if (count < (u32)(a + (s32)off)) {
            *arg3 = -1;
        } else if (count >= (u32)(count18 - U16(p, 8))) {
            *arg3 = -1;
        } else {
            *arg3 = (s16)(((count - off) - a) & 0xFFFFFFFE);
        }
    } else if (mode == 2) {
        count18 = U16(p, 0x18);
        if (count < count18) {
            b = p[0];
            a = U16(p, 4);
            off = (u32)b * 3;
            if (count < (u32)(a + (s32)off)) {
                *arg3 = -1;
            } else if (count >= (u32)(count18 - U16(p, 8))) {
                *arg3 = -1;
            } else {
                *arg3 = (s16)((count - off) - a);
            }
        } else {
            count -= count18;
            b = p[0];
            a = U16(p, 6);
            off = (u32)b * 3;
            if (count < (u32)(a + (s32)off)) {
                *arg3 = -1;
            } else if (count >= (u32)(count18 - U16(p, 10))) {
                *arg3 = -1;
            } else {
                *arg3 = (s16)(((count - off) - a) & 0xFFFFFFFE);
            }
        }
    }

    *arg2 = (u16)(arg0 - 1);
}
