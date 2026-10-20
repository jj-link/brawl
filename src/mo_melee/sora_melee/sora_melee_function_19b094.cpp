#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19B094(void *arg) {
    u8 *p = (u8 *)arg + 8;
    s32 val = *(s32 *)p;
    return val >> 27;
}
