#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_231B1C(void* self) {
    s32 v = *(s32*)((u8*)self + 0x1d8);
    switch (v) {
    case 0:
        return 0x140004B8;
    case 1:
        return 0x14000496;
    case 2:
        return 0x1400047D;
    default:
        return 0;
    }
}
}
