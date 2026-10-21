#pragma force_active on
extern int fn_803EB708(void);

int FAFseek(void) {
    int temp_r3;

    temp_r3 = fn_803EB708();
    return (-temp_r3 | temp_r3) >> 0x1F;
}
