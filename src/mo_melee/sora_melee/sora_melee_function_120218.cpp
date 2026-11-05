#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_120218(u8* self, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (arg1 == *(s32*)(self + 0x330) && arg2 == *(s32*)(self + 0x338)) {
            u32 v;
            if (*(u32*)(self + 0x310) != 0xFFFF && (arg2 == -1 || arg2 == *(s32*)(self + 0x314))) {
                v = *(s32*)(self + 0x310);
            } else if (*(u32*)(self + 0x318) != 0xFFFF && (arg2 == -1 || arg2 == *(s32*)(self + 0x31C))) {
                v = *(s32*)(self + 0x318);
            } else if (*(u32*)(self + 0x320) != 0xFFFF && (arg2 == -1 || arg2 == *(s32*)(self + 0x324))) {
                v = *(s32*)(self + 0x320);
            } else if (*(u32*)(self + 0x328) != 0xFFFF && (arg2 == -1 || arg2 == *(s32*)(self + 0x32C))) {
                v = *(s32*)(self + 0x328);
            } else {
                v = 0xFFFF;
            }
            if (v != 0xFFFF) {
                return v;
            }
        }
        self += 0x30;
    }
    return 0xFFFF;
}
