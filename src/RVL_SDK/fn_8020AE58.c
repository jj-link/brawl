#pragma force_active on
typedef int s32;

extern void fn_8020CC4C(s32 *, s32);
extern s32 fn_8020CA48(s32 *);
extern void fn_8020B34C(int, int *, int *, int *);
extern int fn_80213FC8(int, int, int, int, int, int, int);
extern int fn_80213ED4(int, int, int, int, int);
extern int fn_8020D3E0(int, void *);

s32 fn_8020AE58(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 buf[16];
    s32 v10;
    s32 vC;
    s32 v8;

    buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
    buf[4] = 0; buf[5] = 0; buf[6] = 0; buf[7] = 0;
    buf[8] = 0; buf[9] = 0; buf[10] = 0; buf[11] = 0;
    buf[12] = 0; buf[13] = 0; buf[14] = 0; buf[15] = 0;

    fn_8020CC4C(buf, a);

    if (f == 0 && fn_8020CA48(buf) != 0) {
        return -0x66;
    }

    if (!(b & 0x10)) {
        return -0x65;
    }

    v10 = 0;
    vC = 0;
    v8 = 0;
    fn_8020B34C(b, &v10, &vC, &v8);

    if (e != 0) {
        return fn_80213FC8((int)buf, c, v10, vC, v8, (int)fn_8020D3E0, d);
    }

    return fn_80213ED4((int)buf, c, v10, vC, v8);
}