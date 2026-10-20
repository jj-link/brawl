#pragma force_active on
extern "C" int fn_48_BF74(const unsigned int *p)
{
    unsigned int x = p[2];
    x = (x << 12) | (x >> 20);
    x &= 0xfe000000u;
    return (int)x >> 26;
}
