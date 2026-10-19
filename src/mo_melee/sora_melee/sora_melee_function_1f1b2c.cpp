#include <types.h>
#pragma force_active on

extern "C" u8 fn_27_1F1B2C(u8* self, s32 idx) {
    if (idx >= 0 && idx < 7 && self + 0x4c) {
        u8* node = *(u8**)(self + 0x4c + idx * 4);
        if (node) {
            return node[0x113];
        }
    }
    return 0;
}
