#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

s32 fn_80393270(s32, s32, s32, s32, s32, s32);
s32 fn_803974FC(void);
void *fn_80397564(void);
s32 **fn_80397570(s32);
s32 fn_80397578(s32);

s32 fn_803936B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r29;
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 *ctx;
    u8 *temp_r30;

    temp_r29 = fn_803974FC();
    temp_r30 = (u8 *)fn_80397564();
    temp_r31 = fn_80397578(temp_r29);
    ctx = *fn_80397570(temp_r29);
    temp_r3_2 = ctx[3];
    temp_r4 = temp_r31 + 0x360;
    if (arg2 == 0) {
        return 0;
    }
    temp_r3 = fn_80393270(temp_r3_2, temp_r4, *(s32 *)(temp_r30 + 0x7D0), arg0 + 0x324, arg1, arg2);
    if (temp_r3 < 0) {
        return 1;
    }
    return (((temp_r3 == 0) & 1) * -1) & 2;
}
