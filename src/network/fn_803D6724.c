#include <types.h>
#pragma force_active on

s32 fn_803D6724(void* arg0, u32 arg1) {
    s32* p = (s32*)arg0;
    if (arg1 == 1) {
        return p[0];
    }
    if (arg1 == 2) {
        return p[1];
    }
    return p[2];
}
