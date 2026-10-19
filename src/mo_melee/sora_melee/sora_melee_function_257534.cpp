#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_257534(u8* self) {
    u8 f = self[0x11b];
    if ((f >> 3) & 1) {
        return 0;
    }
    if ((f >> 5) & 1) {
        s32 r = 2;
        if ((f >> 4) & 1) {
            r = 3;
        }
        return r;
    }
    return 1;
}
}
