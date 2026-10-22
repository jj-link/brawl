#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;

extern void *fn_8022EFF8(int);
extern void fn_80242908(void *);

s32 fn_80245158(u8 *arg0) {
    u8 *temp_r3;

    temp_r3 = fn_8022EFF8(2);
    if (temp_r3 == 0) {
        return 0;
    }
    *(s16 *)(temp_r3 + 2) = 9;
    *(u16 *)(temp_r3 + 4) = 0;
    temp_r3[8] = 0xE;
    temp_r3[9] = 4;
    temp_r3[0xA] = 6;
    temp_r3[0xB] = arg0[5];
    temp_r3[0xC] = arg0[4];
    temp_r3[0xD] = arg0[3];
    temp_r3[0xE] = arg0[2];
    temp_r3[0xF] = arg0[1];
    temp_r3[0x10] = arg0[0];
    fn_80242908(temp_r3);
    return 1;
}
