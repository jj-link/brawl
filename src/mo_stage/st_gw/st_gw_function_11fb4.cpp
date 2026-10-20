#pragma force_active on
extern "C" {
int fn_63_11FB4(int *p)
{
    int t = p[2];
    t = (t << 4) & 0xE0000000;
    return t >> 30;
}
}
