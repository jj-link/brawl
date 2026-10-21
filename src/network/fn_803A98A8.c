#include <types.h>
#pragma force_active on

s32 fn_803A98A8(u8 *arg0, u8 *arg1) {
    u8 c;
    u8 d;
    while ((c = *arg0) != 0 && (d = *arg1) != 0 && c == d) {
        arg0++;
        arg1++;
    }
    return c - *arg1;
}
