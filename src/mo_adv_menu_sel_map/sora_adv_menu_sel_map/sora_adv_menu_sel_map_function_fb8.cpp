#include <types.h>
#pragma force_active on

extern "C" s32 fn_31_FB8(s32*, s32* r4) {
    s32 mode = r4[0x3C >> 2];
    switch (mode) {
    case 0:
        if ((r4[1] & (1u << 5)) || (r4[1] & (1u << 10)))
            return 1;
        break;
    case 1:
        if ((r4[1] & (1u << 5)) || (r4[1] & (1u << 10)))
            return 1;
        break;
    case 2:
        if (r4[1] & (1u << 19))
            return 1;
        if ((r4[1] & (1u << 22)) && (r4[1] & (1u << 17)))
            return 1;
        break;
    case 3:
        if (r4[1] & (1u << 17))
            return 1;
        break;
    default:
        break;
    }
    return 0;
}
