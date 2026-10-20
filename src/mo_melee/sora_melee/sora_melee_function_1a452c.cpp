#pragma force_active on
extern "C" int fn_27_1A452C(const unsigned int *p)
{
    unsigned int value = p[2];
    value = (value << 20) & 0xFFE00000u;
    return (int)value >> 22;
}
