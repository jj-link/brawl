#pragma force_active on
extern "C" int fn_74_6BE0(const unsigned int *p)
{
    unsigned int value = (p[2] << 8) & 0xF8000000U;
    return (int)value >> 28;
}
