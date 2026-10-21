#pragma force_active on
extern int fn_803EB72C();

int FAFsfirst(void) {
    int temp_r3;

    temp_r3 = fn_803EB72C();
    return (int)((-temp_r3 | temp_r3) >> 0x1F);
}
