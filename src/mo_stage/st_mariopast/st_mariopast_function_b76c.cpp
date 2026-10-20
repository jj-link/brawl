#pragma force_active on
extern "C" int fn_48_B76C(unsigned int *p)
{
    unsigned int v = p[2];
    unsigned int t = (v >> 10) & 0xFF;
    return (int)(t << 24) >> 25;
}
