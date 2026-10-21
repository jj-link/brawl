#include <types.h>
#pragma force_active on

s32 fn_80211AF8(u8 *arg0, s32 arg1) {
    u8 *p = arg0;
    s32 i = arg1;
    while (*p && i--) {
        p++;
    }
    return p - arg0;
}
