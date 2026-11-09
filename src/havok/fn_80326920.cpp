#include <types.h>

#pragma force_active on

extern "C" {
void fn_802F28BC(s32, s32, s32, unsigned char *, s8 *);
void fn_80327DEC(s32, s32, s32);
void fn_80327FE0(s32, s32);

void fn_80326920(s32 arg0, s32 *arg1, s32 arg2, unsigned char *arg3, const unsigned char *arg4) {
    s8 flag = *arg4;
    fn_802F28BC(arg0, (s32)arg1, arg2, arg3, &flag);
    if (arg2 != 1) {
        fn_80327DEC(arg0, (s32)arg1, arg2);
    } else {
        fn_80327FE0(arg0, *arg1);
    }
}
}
