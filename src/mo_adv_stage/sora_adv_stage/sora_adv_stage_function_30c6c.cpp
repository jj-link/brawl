#pragma force_active on
extern "C" int fn_40_30C6C(const unsigned int *p)
{
    unsigned int value = p[2];
    value <<= 5;
    value &= 0xFC000000U;
    return (int)value >> 27;
}
