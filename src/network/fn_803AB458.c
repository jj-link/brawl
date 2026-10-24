#pragma force_active on

int fn_803AB458(int z, unsigned int a, unsigned int b,
                unsigned int c, unsigned int *p, unsigned int *q) {
    unsigned int t;
    int r = 0;

    *p = a;
    *q = b;
    if (c > 0x200) {
        t = (c >> 9) & 0x7F;
        if (t == 2) *p >>= 1;
        else if (t == 4) *p >>= 2;
        else if (t == 8) *p >>= 3;

        if (t == 2) *q >>= 1;
        else if (t == 4) *q >>= 2;
        else if (t == 8) *q >>= 3;
    } else if (c < 0x200) {
        r = 4;
    }
    return r;
}
