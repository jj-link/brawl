#include <types.h>
#pragma force_active on

extern "C" {
extern u8 g_ftCommonData[];

s32 fn_27_1455BC(u32 unused, u32 p1, u32 p2) {
    return *(s32*)(g_ftCommonData + 0x7018 - 0x30000 + p1 * 0x14 + p2 * 4);
}
}
