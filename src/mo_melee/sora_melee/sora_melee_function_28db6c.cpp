#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_28DB6C(u8* p, s32 bit, s32 flag) {
    if (flag != 0) {
        p[0x8d4] = p[0x8d4] | (1 << bit);
    } else {
        p[0x8d4] = p[0x8d4] & ~(1 << bit);
    }
}
}
