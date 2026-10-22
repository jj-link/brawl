#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern int fn_80210A4C(void *, s32, void *);
extern s32 fn_80210EC8(void *);
extern s32 fn_80210EDC(void *);
extern void fn_80210EE4(void *);

void fn_8027B410(u8 *arg0, s32 arg1, s32 arg2, s8 arg3) {
    u8 sp8[8];
    s32 temp_r30;
    s32 temp_r31;
    u8 *temp_r3;

    if (arg0[0x1EC] != 0) {
        fn_80210A4C(arg0 + 0x1D0, arg2, sp8);
        temp_r30 = fn_80210EC8(sp8);
        temp_r31 = fn_80210EDC(sp8);
        fn_80210EE4(sp8);
        temp_r3 = arg0 + arg1 * 0x68;
        temp_r3[0x5E] = 0;
        *(s32 *)(temp_r3 + 0x58) = arg2;
        *(s32 *)(temp_r3 + 0x54) = temp_r31;
        temp_r3[0x5D] = arg3;
        *(s32 *)(temp_r3 + 0x50) = temp_r30;
    }
}
