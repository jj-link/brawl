#pragma force_active on
extern "C" int fn_48_BC84(unsigned int *p)
{
    unsigned int x = ((p[2] << 12) | (p[2] >> 20)) & 0xFE000000u;
    return (int)x >> 26;
}
