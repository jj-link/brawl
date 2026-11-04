#pragma force_active on
typedef int s32;
extern s32 fn_8020CAD4(void);
extern void fn_8020CC4C(s32 *, s32);
extern s32 fn_8020CA48(s32 *);
extern s32 fn_802140BC(s32 *, s32, s32);
extern s32 fn_8020CAEC(s32);

s32 fn_8020AD88(s32 arg0, s32 arg1, s32 arg2) {
    s32 buf[16];
    s32 r;
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
    buf[4] = 0; buf[5] = 0; buf[6] = 0; buf[7] = 0;
    buf[8] = 0; buf[9] = 0; buf[10] = 0; buf[11] = 0;
    buf[12] = 0; buf[13] = 0; buf[14] = 0; buf[15] = 0;
    fn_8020CC4C(buf, arg0);
    if (fn_8020CA48(buf) != 0) {
        r = -0x66;
    } else {
        r = fn_802140BC(buf, arg1, arg2);
    }
    return fn_8020CAEC(r);
}