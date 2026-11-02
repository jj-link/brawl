#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 fn_803AB1B4(u8 *arg0, s32 *arg1) {
    u8 temp_r5;
    u8 temp_r0;
    u16 temp_r0_2;

    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }
    *arg1 = 1;
    temp_r5 = arg0[0];
    if ((temp_r5 != 0xEB || arg0[2] != 0x90) && temp_r5 != 0xE9) {
        *arg1 = 0;
    }
    if (arg0[0x1FE] != 0x55 || arg0[0x1FF] != 0xAA) {
        *arg1 = 0;
    }
    temp_r0_2 = arg0[0xB] | (arg0[0xC] << 8);
    if (temp_r0_2 != 0x200 && temp_r0_2 != 0x400 && temp_r0_2 != 0x800 && temp_r0_2 != 0x1000) {
        *arg1 = 0;
    }
    temp_r0 = arg0[0xD];
    if (temp_r0 != 1 && temp_r0 != 2 && temp_r0 != 4 && temp_r0 != 8 && temp_r0 != 0x10 && temp_r0 != 0x20 && temp_r0 != 0x40 && temp_r0 != 0x80) {
        *arg1 = 0;
    }
    temp_r0 = arg0[0x15];
    if (temp_r0 != 0xF0 && temp_r0 != 0xF8 && temp_r0 != 0xF9 && temp_r0 != 0xFA && temp_r0 != 0xFB && temp_r0 != 0xFC && temp_r0 != 0xFD && temp_r0 != 0xFE && temp_r0 != 0xFF) {
        *arg1 = 0;
    }
    return 0;
}
