#pragma force_active on
extern "C" int fn_48_BA5C(int *p)
{
    unsigned int v = (unsigned int)p[2];
    v = (v << 12) | (v >> 20);
    v &= 0xFE000000;
    return (int)v >> 26;
}
