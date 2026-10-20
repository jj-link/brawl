#pragma force_active on
extern "C" int fn_40_30AA8(const unsigned int *p)
{
    return (int)((p[2] << 10) & 0xFC000000u) >> 27;
}
