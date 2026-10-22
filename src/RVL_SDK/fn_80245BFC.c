#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern void *fn_8022EFF8(s32);
extern void fn_80242908(void *);

s32 fn_80245BFC(u8 *arg0, s8 arg1) {
    u8 *temp_r3;

    temp_r3 = (u8 *)fn_8022EFF8(2);
    if (temp_r3 == 0) {
        return 0;
    }
    *(s16 *)(temp_r3 + 2) = 10;
    *(s16 *)(temp_r3 + 4) = 0;
    temp_r3[8] = 11;
    temp_r3[9] = 8;
    temp_r3[10] = 7;
    temp_r3[11] = arg0[5];
    temp_r3[12] = arg0[4];
    temp_r3[13] = arg0[3];
    temp_r3[14] = arg0[2];
    temp_r3[15] = arg0[1];
    temp_r3[16] = arg0[0];
    temp_r3[17] = arg1;
    fn_80242908(temp_r3);
    return 1;
}
