#include <types.h>
#pragma force_active on

s32 fn_80336674(u16 *arg0) {
    s32 count = 0;
    while (*arg0 != 0) {
        arg0++;
        count++;
    }
    return count;
}
