#pragma force_active on
extern int fn_803EB7C4();

int FAFstat(void) {
    int temp_r3;
    temp_r3 = fn_803EB7C4();
    return (-temp_r3 | temp_r3) >> 31;
}
