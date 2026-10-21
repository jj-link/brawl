#include <stddef.h>
#pragma force_active on
typedef signed int s32;

s32 fn_803D72C0(s32 arg0, s32 *arg1) {
    s32 r;
    *arg1 = 0;
    r = fn_803D79B0();
    return r & ((-r | r) >> 31);
}
