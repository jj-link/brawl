#pragma force_active on
int fn_803A962C(int a) {
    if (a < 0x61)
        return a;
    if (a <= 0x7A)
        return a - 0x20;
    return a;
}
