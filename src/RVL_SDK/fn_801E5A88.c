#pragma force_active on

typedef unsigned int u32;
typedef int s32;

extern s32 fn_801E4B7C(s32, s32);
extern s32 fn_801E54E0(s32, s32, s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4E7C(s32);
extern void fn_801E55DC(s32);
extern s32 fn_801E4C94(s32);

s32 fn_801E5A88(s32 arg0, s32 arg1, u32 *arg2) {
    s32 err;
    s32 t;
    u32 cmd;
    s32 val;

    if (arg0 != 2 && arg1 == 0 && fn_801E4B7C(arg0, 0) == 0) {
        return 0;
    }

    err = (fn_801E54E0(arg0, arg1, 0) == 0);
    if (!err) {
        err = (fn_801E4D4C(arg0, arg1, 0) == 0);
        if (!err) {
            cmd = 0x20011300;
            t = (fn_801E42E4(arg0, &cmd, 4, 1, 0) == 0);
            err = t | (fn_801E46FC(arg0) == 0);
            err |= (fn_801E42E4(arg0, arg2, 4, 0, 0) == 0);
            err |= (fn_801E46FC(arg0) == 0);
            err |= (fn_801E4E7C(arg0) == 0);
        }
        fn_801E55DC(arg0);
    }

    if (arg0 != 2 && arg1 == 0) {
        fn_801E4C94(arg0);
    }

    if (err != 0) {
        return 0;
    }

    val = (s32)*arg2;
    return (u32)((-val - 1) | (val + 1)) >> 31;
}
