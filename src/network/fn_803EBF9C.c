#pragma force_active on
extern int fn_803EB84C(signed char);

int fn_803EBF9C(signed char arg0) {
    int r3 = fn_803EB84C(arg0);
    return (-r3 | r3) >> 0x1F;
}
