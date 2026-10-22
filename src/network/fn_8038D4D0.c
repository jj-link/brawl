#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 fn_8038D77C(void *self, s32 flags, s32 a, s32 b, s32 c);
extern void fn_8038D84C(s32 arg);
extern s32 fn_8038E2AC(s32 arg);

s32 fn_8038D4D0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 r;
    s32 ret;
    s32 t;

    r = fn_8038D77C(arg0, 0, arg1, arg2, arg3);
    ret = r;
    if (r == 0) {
        ret = 0;
    } else {
        t = fn_8038E2AC(r);
        *(s32 *)((u8 *)arg0 + 0x48) = t;
        if (t != 0) {
            fn_8038D84C(ret);
            ret = 0;
        }
    }
    return ret;
}
