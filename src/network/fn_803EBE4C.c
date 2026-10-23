#pragma force_active on
int fn_803EB5FC(void);

int fn_803EBE4C(void) {
    int v = fn_803EB5FC();
    if (v == 5)
        return 5;
    return v & ~(-(v == 0));
}
