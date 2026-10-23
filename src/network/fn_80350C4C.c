#pragma force_active on
int fn_80350C4C(unsigned *p) {
    unsigned x = *p >> 11;
    int r;
    if ((x & 3) == 3)
        r = (x >> 2) & 1;
    else
        return 0;
    return r;
}