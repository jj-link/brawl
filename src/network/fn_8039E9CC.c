#include <types.h>
#pragma force_active on

s32 fn_8039E9CC(u8 *arg0) {
    u8 temp_r0;
    u8 c;
    u8 *p;

    temp_r0 = arg0[0xC8];
    if (temp_r0 == 0) {
        return -5;
    }
    if (temp_r0 > 8) {
        return -3;
    }
    p = *(u8 **)(arg0 + 0x40);
    if (p == NULL) {
        goto tail;
    }
    goto cond;

body:
    if ((s8)c == 0xD) {
        if ((s32)p[1] != 0xA) {
            return -0x18;
        }
    }
    if ((s8)c == 0xA) {
        if ((s32)p[1] != 0x20) {
            return -0x18;
        }
    }
    p++;
cond:
    c = *p;
    if ((s8)c != 0) {
        goto body;
    }

tail:
    if (arg0[0xC9] > 2) {
        return -3;
    }
    return 0;
}
