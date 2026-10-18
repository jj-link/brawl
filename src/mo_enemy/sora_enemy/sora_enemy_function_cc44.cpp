#include <types.h>
#pragma force_active on

extern "C" {
s32* fn_41_CD5C(s32* obj, s32 index);

void fn_41_CC44(s32* obj, u32 p2, s32 (*p3)(s32, s32)) {
    if (p2 == 0xFFFF) {
        return;
    }
    for (u32 i = 0; i < (u32)obj[0]; i++) {
        if (i == p2) {
            continue;
        }
        s32* entry = fn_41_CD5C(obj, (s32)i);
        if (entry) {
            if (*(u8*)entry != 0) {
                if (p3(p2, entry[3]) == 0) {
                    return;
                }
            }
        }
    }
}
}
