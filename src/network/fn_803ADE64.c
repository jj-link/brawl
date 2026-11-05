#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern s32 fn_803AB808(void);
extern s32 fn_803ABF18(s32, u8 *, s32, s32, u32, u32 *);
extern s32 fn_803AE0F4(s32, u8 *, s32 *);
extern s32 fn_803ADD50(u8 *, s32, s32);

s32 fn_803ADE64(s32 arg0, s32 arg1) {
    u8 buf[0x200];
    u32 spC;
    s32 flag;
    s32 r;

    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    r = fn_803AB808();
    if (r != 0) {
        return r;
    }
    r = fn_803ABF18(arg0, buf, 0, 1, 0x200, &spC);
    if (r != 0) {
        return r;
    }
    fn_803AE0F4(arg0, buf, &flag);
    if (flag != 0) {
        fn_803ADD50(buf, 0, arg1);
    } else {
        return 5;
    }
    return 0;
}
