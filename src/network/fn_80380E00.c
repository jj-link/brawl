#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct Blk {
    u8 pad0;
    u8 b1;
    s16 h2;
    s32 w4;
} Blk;

extern s32 lbl_8059FA50;
extern u16 lbl_805A1060;
extern s32 lbl_805A1064;

s16 SOHtoNs(u16);
s32 fn_8035C384(s32, void *, s32);
s32 fn_8035C658(s32);
s32 fn_8035C660(s32, s32, s32 *, s32 *);
s32 fn_8035CD04(s32, s32);
void fn_8035CD7C(s32, s32);
void fn_8037BDD4(void *, s32, s32);
void *memset(void *, s32, s32);
s32 socket(s32, s32, s32);

void fn_80380E00(void *arg0)
{
    u8 *self = (u8 *)arg0;
    Blk blk;
    s32 spC;
    s32 sp8;
    s32 temp_r3;
    s32 err;

    if (*(s32 *)(self + 0x4C) == -1) {
        temp_r3 = socket(2, 1, 6);
        *(s32 *)(self + 0x4C) = temp_r3;
        if (temp_r3 == -1) {
            *(s32 *)(self + 0x120) = 1;
            *(s32 *)(self + 0x3C) = 5;
            *(s32 *)(self + 0x50) = fn_8035C658(temp_r3);
            return;
        }
        if (fn_8035CD04(temp_r3, 0) == 0) {
            *(s32 *)(self + 0x120) = 1;
            *(s32 *)(self + 0x3C) = 5;
            *(s32 *)(self + 0x50) = fn_8035C658(*(s32 *)(self + 0x4C));
            return;
        }
        if (*(s32 *)(self + 0x158) != 0) {
            fn_8035CD7C(*(s32 *)(self + 0x4C), lbl_8059FA50);
        }
        memset(&blk, 0, 8);
        blk.b1 = 2;
        if (*(s32 *)(self + 0x188) != 0) {
            blk.h2 = SOHtoNs(*(u16 *)(self + 0x18C));
        } else if (lbl_805A1064 != 0) {
            blk.h2 = SOHtoNs(lbl_805A1060);
        } else {
            blk.h2 = SOHtoNs(*(u16 *)(self + 0x20));
        }
        blk.w4 = *(s32 *)(self + 0x1C);
        if (fn_8035C384(*(s32 *)(self + 0x4C), &blk, 8) == -1) {
            err = fn_8035C658(*(s32 *)(self + 0x4C));
            if (err != -6 && err != -0x1A && err != -0x4C) {
                *(s32 *)(self + 0x120) = 1;
                *(s32 *)(self + 0x3C) = 6;
                *(s32 *)(self + 0x50) = err;
                return;
            }
        }
    }

    temp_r3 = fn_8035C660(*(s32 *)(self + 0x4C), 0, &spC, &sp8);
    if (temp_r3 == -1 || (temp_r3 == 1 && sp8 != 0)) {
        *(s32 *)(self + 0x120) = 1;
        *(s32 *)(self + 0x3C) = 6;
        if (temp_r3 == -1) {
            *(s32 *)(self + 0x50) = fn_8035C658(*(s32 *)(self + 0x4C));
            return;
        }
        *(s32 *)(self + 0x50) = 0;
        return;
    }
    if (temp_r3 == 1 && spC != 0) {
        if (*(s32 *)(self + 0x194) == 0) {
            *(s32 *)(self + 0x10) = 5;
        } else {
            *(s32 *)(self + 0x10) = 4;
        }
        fn_8037BDD4(self, 0, 0);
    }
}
