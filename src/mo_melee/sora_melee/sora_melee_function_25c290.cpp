#include <types.h>
#pragma force_active on

extern "C" void fn_27_25C290(u8 *p) {
    u32 cur = *(u32 *)(p + 0x4c);
    u32 max = *(u32 *)(p + 0x54);
    if (cur < max) {
        *(u32 *)(p + 0x4c) = cur + 1;
    } else {
        *(u32 *)(p + 0x48) = 4;
    }
}
