#pragma force_active on
extern "C" int fn_48_BDB0(int *p)
{
    unsigned int x = (unsigned int)p[2];
    x = (x << 6) & 0xFE000000;
    return (int)x >> 26;
}
