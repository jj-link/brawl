#include <types.h>
#pragma force_active on

s32 fn_8035B1C4(s32, s32 *);

s32 fn_80370758(void **arg0, s32 arg1, s32 *arg2) {
    s32 buf[6];
    u8 *p;
    s32 temp_r3;

    p = (u8 *)*arg0;
    buf[0] = arg1;
    temp_r3 = fn_8035B1C4(*(s32 *)(p + 0x444), &buf[0]);
    if (arg2 != NULL) {
        *arg2 = temp_r3;
    }
    return temp_r3 != 0;
}
