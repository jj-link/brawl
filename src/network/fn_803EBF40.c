#pragma force_active on
typedef int s32;

s32 fn_803EB7A0(void);

s32 FAFsnext(void) {
    s32 temp_r3;

    temp_r3 = fn_803EB7A0();
    return (-temp_r3 | temp_r3) >> 0x1F;
}
