#include <types.h>
#pragma force_active on

extern "C" {
s32* fn_41_CD5C(s32* obj, s32 index);
s32 fn_27_8CC68(s32 p1, s32 p2);

u32 fn_41_D108(s32* obj, s32 p2) {
    for (u32 i = 0; i < (u32)obj[0]; i++) {
        s32* entry = fn_41_CD5C(obj, (s32)i);
        if (entry == 0) {
            continue;
        }
        if (*(u8*)entry == 0) {
            continue;
        }
        s32 v = entry[5];
        if (v == 0) {
            continue;
        }
        if (fn_27_8CC68(v, p2) == -1) {
            continue;
        }
        return entry[3];
    }
    return 0xFFFF;
}
}
