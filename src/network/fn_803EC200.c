#pragma force_active on
typedef signed int s32;

s32 fn_803EB9C8(void);

s32 FARemove(void) {
    s32 temp_r3;

    temp_r3 = fn_803EB9C8();
    return (-temp_r3 | temp_r3) >> 0x1F;
}
