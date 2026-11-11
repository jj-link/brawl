#include <types.h>
#include <stddef.h>
#pragma force_active on

extern int fn_803F6150(const void *, const void *, u32);
extern void *memcpy(void *, const void *, u32);
extern int lbl_8040DAE8[4];

u8 fn_8025BBD0(const u8 *arg0, u32 arg1, const u8 *arg2, u32 arg3) {
    u8 sp18[0x10];
    u8 sp8[0x10];
    u8 result;

    if (arg1 == arg3) {
        if (arg1 == 2) {
            result = 0;
            if (arg0[0] == arg2[0] && arg0[1] == arg2[1]) {
                result = 1;
            }
            return result;
        }
        if (arg1 == 4) {
            result = 0;
            if (arg0[0] == arg2[0] && arg0[1] == arg2[1] &&
                arg0[2] == arg2[2] && arg0[3] == arg2[3]) {
                result = 1;
            }
        } else {
            result = fn_803F6150(arg0, arg2, arg1) == 0;
        }
        return result;
    }
    if (arg1 > arg3) {
        if (arg1 == 4) {
            result = 0;
            if (arg0[0] == 0 && arg0[1] == 0 && arg0[2] == arg2[0] &&
                arg0[3] == arg2[1]) {
                result = 1;
            }
            return result;
        }
        memcpy(sp18, arg0, 0x10);
        memcpy(sp8, lbl_8040DAE8, 0x10);
        if (arg3 == 4) {
            memcpy(sp8, arg2, arg3);
        } else {
            memcpy(sp8 + 2, arg2, arg3);
        }
        result = fn_803F6150(sp18, sp8, 0x10) == 0;
        return result;
    }
    if (arg3 == 4) {
        result = 0;
        if (arg2[0] == 0 && arg2[1] == 0 && arg2[2] == arg0[0] &&
            arg2[3] == arg0[1]) {
            result = 1;
        }
        return result;
    }
    memcpy(sp8, arg2, 0x10);
    memcpy(sp18, lbl_8040DAE8, 0x10);
    if (arg1 == 4) {
        memcpy(sp18, arg0, arg1);
    } else {
        memcpy(sp18 + 2, arg0, arg1);
    }
    return fn_803F6150(sp18, sp8, 0x10) == 0;
}
