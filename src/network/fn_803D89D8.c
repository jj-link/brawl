#include <types.h>
#pragma force_active on

extern s32 fn_803D7B04(void *, void *);
extern s32 fn_803D7B50(void *);

s32 fn_803D89D8(void *arg0) {
    s32 r;
    if (((s32 *)arg0)[0] & 4) {
        goto flagged;
    }
    r = fn_803D7B04(((void **)arg0)[1], arg0);
    if (r != 0) {
        return r;
    }
    r = fn_803D7B50(((void **)arg0)[1]);
    if (r != 0) {
        return r;
    }
    goto success;
flagged:
    return 0xB;
success:
    ((s32 *)arg0)[0] |= 4;
    return 0;
}