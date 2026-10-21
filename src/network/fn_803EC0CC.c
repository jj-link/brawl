#pragma force_active on
typedef int s32;

s32 fn_803EB8F8(void);

s32 fn_803EC0CC(void) {
    s32 temp_r3;

    temp_r3 = fn_803EB8F8();
    return (-temp_r3 | temp_r3) >> 0x1F;
}
