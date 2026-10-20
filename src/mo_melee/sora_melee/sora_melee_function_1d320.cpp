#pragma force_active on
extern "C" int fn_27_1D320(const unsigned int *p)
{
    unsigned int value = p[2] << 6;
    value &= 0xFE000000;
    return (int)value >> 26;
}
