#pragma force_active on
typedef int s32;

extern void fn_8020CC4C(s32 *, s32);
extern s32 fn_8020CA48(s32 *);
extern int fn_80214DB8(s32 *, s32);
extern int fn_80214E80(s32 *, s32, s32, s32);
extern void fn_8020BBC4(void);

s32 fn_8020B8A8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 buf[16];
    s32 mode;

    buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
    buf[4] = 0; buf[5] = 0; buf[6] = 0; buf[7] = 0;
    buf[8] = 0; buf[9] = 0; buf[10] = 0; buf[11] = 0;
    buf[12] = 0; buf[13] = 0; buf[14] = 0; buf[15] = 0;

    mode = 0;

    fn_8020CC4C(buf, a);

    if (e == 0 && fn_8020CA48(buf) != 0) {
        return -0x66;
    }

    switch (b) {
    case 3:
        mode = 3;
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    }

    if (d != 0) {
        return fn_80214E80(buf, mode, (s32)fn_8020BBC4, c);
    }

    return fn_80214DB8(buf, mode);
}
