#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1F2C78(u8* p) {
    u8 c = *p;
    s32 x = (s8)c;
    if (x >= 0 && x < 14) {
        return x % 7;
    }
    return (s8)c;
}
}
