#pragma force_active on
typedef int s32;
typedef unsigned char u8;

struct Lbl80598080 {
    void (*fp0)(signed char);
    void (*fp1)(signed char);
    u8 pad[0x18 - 8];
};

extern struct Lbl80598080 lbl_80598080;
extern void fn_803EC1BC(signed char arg);
extern void fn_803EC1DC(signed char arg);
s32 fn_803EE8F8(s32 a, s32 b, s32 c, s32 d);

s32 fn_803EC154(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;
    switch (arg0) {
    case 0:
        lbl_80598080.fp0 = (void (*)(signed char))arg1;
        lbl_80598080.fp1 = (void (*)(signed char))arg2;
        ret = fn_803EE8F8((s32)fn_803EC1BC, (s32)fn_803EC1DC, arg2, (s32)&lbl_80598080);
        break;
    default:
        ret = -2;
        return ret;
    }
    ret = (ret != 0);
    return -ret;
}
