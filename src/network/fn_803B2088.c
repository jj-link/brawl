#include <types.h>
#pragma force_active on

s32 fn_803B2088(s32 arg0, u32 arg1, s32 arg2) {
    s32 result = 1;
    s32 b;
    s32 a;

    if (arg0 == 0) {
        arg0 = 0x40;
    }
    if (arg1 & 0x80) {
        a = arg1 & 0x7F;
        b = arg2 & 0x7F;
        if ((a != 0 && a != (a & arg0)) || (b != 0 && b == (b & arg0))) {
            result = 0;
        }
    } else if (arg1 != 0x7F && (u32)arg0 != arg1 && (!(arg0 & arg1) || (arg0 & arg2))) {
        result = 0;
    }
    return result;
}
