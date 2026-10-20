#pragma force_active on
extern "C" int fn_27_19D240(int *p)
{
    unsigned x = (unsigned)p[2];
    int y = (int)((x << 8 | x >> 24) & 0xF8000000u);
    return y >> 28;
}
