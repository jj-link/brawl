#pragma force_active on
extern "C" int fn_27_1A1DE4(const unsigned int *p)
{
    unsigned int x = p[2] << 12;
    x &= 0xFE000000u;
    return (int)x >> 26;
}
