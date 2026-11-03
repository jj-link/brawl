#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E4E7C(s32);
extern s32 fn_801E54E0(s32, s32, s32);
extern void fn_801E55DC(s32);
extern s32 fn_802284C4(void);

extern s32 lbl_805A0CC0;
extern s32 lbl_805A0CC4;
extern s32 lbl_805A0CCC;
extern s32 lbl_805A3750;

s32 fn_80228608(u8 *arg0, u32 arg1)
{
    u8 *p;
    s32 temp;
    s32 r27;
    s32 ret;
    u32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;

    if (lbl_805A0CCC != 0xA5FF005A) {
        return 2;
    }
    if (lbl_805A0CC0 == 0 && fn_802284C4() == 0) {
        return 2;
    }
    if (lbl_805A0CC0 == 0) {
        lbl_805A0CC4 = 1;
        return 2;
    }
    if (fn_801E54E0(0, 1, 0) == 0) {
        return 0;
    }

    p = arg0;
    while ((u32)(p - arg0) < arg1) {
        if ((s32)*p == 0xA) {
            *p = 0xD;
        }
        p++;
    }

    temp = lbl_805A3750;
    ret = 0;
    sp14 = 0xB0000100;

    while (arg1 != 0) {
        if (fn_801E4D4C(0, 1, temp) == 0) {
            r27 = -1;
        } else {
            sp8 = 0x30000100;
            fn_801E42E4(0, &sp8, 4, 1, 0);
            fn_801E46FC(0);
            fn_801E42E4(0, &spC, 4, 0, 0);
            fn_801E46FC(0);
            fn_801E4E7C(0);
            r27 = 0x20 - ((spC >> 24) & 0x3F);
        }

        if (r27 < 0) {
            ret = 3;
            break;
        }
        if (r27 == 0x20) {
            if (fn_801E4D4C(0, 1, temp) == 0) {
                ret = 3;
                break;
            }
            fn_801E42E4(0, &sp14, 4, 1, 0);
            fn_801E46FC(0);
            while (r27 > 0 && arg1 != 0) {
                sp10 = (u32)*arg0 << 24;
                fn_801E42E4(0, &sp10, 4, 1, 0);
                fn_801E46FC(0);
                arg0++;
                r27--;
                arg1--;
            }
            fn_801E4E7C(0);
        }
    }

    fn_801E55DC(0);
    return ret;
}
