#include <types.h>
#pragma force_active on

int fn_8020F4C4(int *out, u32 id);

s32 fn_802100A0(void) {
    int sp8;

    if (fn_8020F4C4(&sp8, 7) == 0) {
        sp8 = 0;
    }
    return sp8;
}
