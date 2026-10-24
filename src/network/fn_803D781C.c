#pragma force_active on

int fn_803D781C(int z, int a, int b, unsigned int c, int *p, int *q)
{
    unsigned int t;
    int r = 0;

    *p = a;
    *q = b;
    if (c > 0x200) {
        t = (c >> 9) & 0x7F;
        if (t == 2) *p *= 2;
        else if (t == 4) *p *= 4;
        else if (t == 8) *p *= 8;

        if (t == 2) *q *= 2;
        else if (t == 4) *q *= 4;
        else if (t == 8) *q *= 8;
    } else if (c < 0x200) {
        r = 4;
    }
    return r;
}
