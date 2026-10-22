#pragma force_active on
typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern s32 fn_8035A590(s32);
extern s32 fn_8036A1A4(s32, u8 *, s8);
extern s32 fn_8036A3E4(s32, s32, u8 *, s32, s32 *, s32 *, char *);
extern char lbl_8059F69C;

s32 fn_8036A4E8(s32 arg0, u8 *arg1, u8 arg2) {
    u8 sp8;
    s32 sp10;
    s32 spC;
    s32 temp_r3;

    sp8 = arg2;
    if ((*(s32 *)(arg1 + 0x34) - *(s32 *)(arg1 + 0x38)) == 0 &&
        fn_8035A590(*(s32 *)(arg1 + 0x3C)) == 0) {
        temp_r3 = fn_8036A3E4(arg0, *(s32 *)(arg1 + 0x8), &sp8, 1, &sp10, &spC, &lbl_8059F69C);
        if (temp_r3 != 0) {
            return temp_r3;
        }
        if (spC != 0) {
            return 0;
        }
    }
    return fn_8036A1A4(arg0, arg1 + 0x2C, (s8)sp8);
}
