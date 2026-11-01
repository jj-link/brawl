#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void fn_802319E4(s32, void *);
extern void fn_802319FC(s32, void *, s32);
extern void fn_80231A14(s32, void *, u8, u32);
extern s32 fn_80259030(s32, void *);
extern s32 fn_802590D0(u8 *, s32, s32, u16, u32, u32);
extern u8 *fn_8025BA20(u8 *, u8, u32 *);
extern u8 lbl_80484C80[];
extern u8 lbl_8052D9C0[];

#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))

u8 *fn_80258E44(u8 *arg0, u8 *arg1, u8 *arg2)
{
    u8 *base = lbl_80484C80;
    u8 *p = arg1 + 1;
    u32 spC;
    u32 sp8;
    u8 first;
    u8 *result;
    u8 current;
    u8 *end;
    s32 val;
    u8 *next;
    u16 word;

    first = *arg1;
    if ((first >> 3) != 6) {
        if (lbl_8052D9C0[0x4630] >= 2) {
            fn_802319FC(0xA0001, base + 0x50, first);
        }
        return 0;
    }

    result = fn_8025BA20(p, first, &spC);
    if (result + spC > arg2) {
        if (lbl_8052D9C0[0x4630] >= 2) {
            fn_802319FC(0xA0001, base + 0x78, spC);
        }
        return 0;
    }

    val = fn_80259030(S32AT(arg0, 0x410), arg0 + 2);
    if (val == 0) {
        if (lbl_8052D9C0[0x4630] >= 2) {
            fn_802319E4(0xA0001, base + 0x98);
        }
        return 0;
    }

    end = result + spC;
    while (result < end) {
        current = *result;
        next = fn_8025BA20(result + 1, current, &sp8);
        if (((current >> 3) & 0x1F) != 1 || sp8 != 2) {
            if (lbl_8052D9C0[0x4630] >= 2) {
                fn_80231A14(0xA0001, base + 0xa8, current, sp8);
            }
            return 0;
        }
        word = (u16)((next[0] << 8) + next[1]);
        result = (u8 *)fn_802590D0(next + 2, S32AT(arg0, 0x410), val, word, 0, 0);
        if (result == 0) {
            if (lbl_8052D9C0[0x4630] >= 2) {
                fn_802319E4(0xA0001, base + 0x98);
            }
            return 0;
        }
    }
    return result;
}
