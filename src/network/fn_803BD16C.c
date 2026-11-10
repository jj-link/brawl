#include <types.h>
#pragma force_active on
typedef struct { u32 first, second, third, mode; } Arg;
typedef struct { double lo, hi; } Copy;
typedef union { struct { u32 first, second, third, mode; } f; Copy dd; } Buf;
typedef union { double d[2]; Copy c; u32 w[4]; } Tmp;
extern u32 fn_803A9A78(void *);
extern void fn_803A9A70(void *, s32);
extern void fn_803A9AD0(void *, s16);
extern u16 fn_803A9C60(void *);
extern s32 fn_803A9DF8(void *, void *, u32, s32, u16);
extern s32 fn_803BE044(Buf *, s32);
extern char lbl_8059FE60;
extern char lbl_8059FE64;
s32 fn_803BD16C(Arg *arg0, u32 *arg1, u32 *arg2, s32 arg3) {
    Buf buf;
    Tmp tmp;
    u32 var_r31;
    s32 ctx;
    s32 ret;
    if (arg1 == 0) return 10;
    ctx = fn_803A9A78(arg0);
    fn_803A9A70(arg1, ctx);
    fn_803A9A70(arg2, ctx);
    arg1[0] = 0;
    if (arg2 != 0) arg2[0] = 0;
    if (fn_803A9DF8(arg0, &lbl_8059FE60, 1, 1, 1) == 0) fn_803A9AD0(arg0, 2);
    var_r31 = arg0->first;
    buf.f.first = var_r31;
    buf.f.second = var_r31;
    buf.f.mode = ctx;
    ret = fn_803BE044(&buf, arg3);
    if (ret != 0) return ret;
    if (buf.f.first == 0 || fn_803A9C60(&buf) == 0) return 2;
    if (arg0->second < buf.f.second) return 2;
    tmp.c = buf.dd;
    for (;;) {
        if (fn_803A9DF8(&buf, &lbl_8059FE64, 2, 0, 1) == 0) {
            var_r31 = tmp.w[1];
            break;
        }
        ret = fn_803BE044(&buf, arg3);
        if (ret != 0) return ret;
        if (fn_803A9C60(&buf) == 0) return 2;
        if (arg0->second < buf.f.second) break;
        if (buf.f.first == 0) break;
        var_r31 = tmp.w[1];
        tmp.c = buf.dd;
    }
    arg1[0] = arg0->first;
    arg1[1] = var_r31;
    if (arg2 != 0) {
        arg2[0] = tmp.w[0];
        arg2[1] = tmp.w[1];
        arg2[2] = tmp.w[2];
        arg2[3] = tmp.w[3];
    }
    return 0;
}