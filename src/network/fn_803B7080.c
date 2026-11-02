#include <types.h>
#pragma force_active on

s32 fn_803B6DC8(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);

s32 fn_803B7080(void *arg0, u32 arg1, s32 arg2, s32 arg3) {
    u32 sp8[2];
    s32 temp_r3;
    u32 temp_r6;
    u8 *temp_r7;
    u8 *temp_r6_2;
    s32 temp_r0;
    u32 temp_r0_2;

    if (arg0 == NULL) {
        return 0xA;
    }
    temp_r7 = *(u8 **)((u8 *)arg0 + 0x30);
    if (temp_r7 == NULL) {
        return 0xA;
    }
    temp_r6 = *(u32 *)arg0;
    if (temp_r6 == 0) {
        return 0xA;
    }
    if (*(u32 *)(temp_r7 + 8) > temp_r6) {
        return 0xA;
    }
    temp_r6_2 = *(u8 **)((u8 *)arg0 + 0x34);
    temp_r0 = (s8)temp_r6_2[0x187A];
    if (temp_r0 < 0x41 || temp_r0 > 0x5A) {
        return 0x23;
    }
    temp_r0_2 = 0xFFFFFFFFU >> temp_r6_2[0x20];
    if (arg1 >= temp_r0_2 + 1) {
        return 0x25;
    }
    temp_r3 = fn_803B6DC8(arg0, arg1, (u32)(-arg2 | arg2) >> 31, 0, arg3, sp8);
    switch (temp_r3) {
    case 0:
        return 0;
    default:
        return temp_r3;
    }
}
