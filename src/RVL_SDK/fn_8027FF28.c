#pragma force_active on
typedef int s32;
typedef unsigned char u8;

void fn_8027FF28(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r8;
    u8 *temp_r3;

    temp_r8 = *(s32 *)(arg0 + 0x2C);
    *(s32 *)(arg0 + 0x2C) = temp_r8 + 1;
    temp_r3 = arg0 + temp_r8 * 0x14;
    temp_r3[0x30] = 1;
    *(s32 *)(temp_r3 + 0x34) = arg2;
    *(s32 *)(temp_r3 + 0x38) = arg1;
    *(s32 *)(temp_r3 + 0x3C) = arg3;
    temp_r3[0x40] = 1;
}
