#pragma force_active on
extern "C" int fn_48_BE78(int *p)
{
    unsigned x = (unsigned)p[2];
    return ((int)(((x << 6) | (x >> 26)) & 0xFE000000u)) >> 26;
}
