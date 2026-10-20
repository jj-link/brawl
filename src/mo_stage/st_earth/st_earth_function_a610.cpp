#pragma force_active on
extern "C" int fn_66_A610(const unsigned int *p)
{
    unsigned int x = p[2];
    return (int)(((x << 4) | (x >> 28)) & 0xF8000000u) >> 28;
}
