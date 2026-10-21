#include <types.h>
#pragma force_active on

extern "C" bool fn_80190DFC(s32** arg0, s32 arg1) {
    s32* p = *arg0;
    if (p != 0 && arg1 >= 0 && arg1 <= 7) {
        return ((1 << arg1) & *p) != 0;
    }
    return false;
}
