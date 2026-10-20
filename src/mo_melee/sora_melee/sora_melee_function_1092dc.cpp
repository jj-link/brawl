#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1092DC(u8* p) {
    s32 ret = 0;
    if (p[0x6a] != 2) {
        u32 bit = (p[0x6e] >> 5) & 1;
        if (bit == 1u) {
            ret = 1;
        }
    }
    return ret;
}
