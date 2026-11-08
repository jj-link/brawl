#include <types.h>
#pragma force_active on

extern u32 lbl_8059C800;

extern "C" {
s32 fn_8004C0D4(u8* arg0, s32 arg1) {
    u16 temp_r0;
    u16 temp_r4;
    u16 temp_r4_2;

    if (*(u32*)(arg0 + 0x0) != lbl_8059C800) {
        return 0;
    }
    temp_r0 = *(u16*)(arg0 + 0x4);
    if (temp_r0 == 0 || temp_r0 > 4) {
        return 0;
    }
    if (*(u16*)(arg0 + 0x6) == 0) {
        return 0;
    }
    if (*(u32*)(arg0 + 0x10) > (u32)(arg1 - 0x388)) {
        return 0;
    }
    temp_r4 = *(u16*)(arg0 + 0x338);
    if ((temp_r4 != 0 && *(u16*)(arg0 + 0x33A) == 0) || (temp_r4 == 0 && *(u16*)(arg0 + 0x33A) != 0)) {
        return 0;
    }
    temp_r4_2 = *(u16*)(arg0 + 0x33C);
    if ((temp_r4_2 != 0 && *(u16*)(arg0 + 0x33E) == 0) || (temp_r4_2 == 0 && *(u16*)(arg0 + 0x33E) != 0)) {
        return 0;
    }
    return 1;
}
}
