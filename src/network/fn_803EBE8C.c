#pragma force_active on
extern int fn_803EB620(void);

int FAFclose(void) {
    int temp_r3;

    temp_r3 = fn_803EB620();
    return (-temp_r3 | temp_r3) >> 31;
}
