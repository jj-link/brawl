#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 fn_803D6A50(s32 a, u8 *buf, s32 b, s32 c, s32 d);
extern u8 lbl_8059FF08;
extern u8 lbl_8059FF09;

s32 fn_803E8860(s32 a) {
    u8 buf[2];
    s32 result = 0;

    buf[0] = lbl_8059FF08;
    buf[1] = lbl_8059FF09;
    if (fn_803D6A50(a, buf, 1, 0, 2) == 0) {
        result = 1;
    }
    return result;
}
