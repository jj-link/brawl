#pragma force_active on
extern "C" int fn_27_88CF0(const unsigned int *p)
{
    unsigned int value = p[2] << 6;
    value &= 0xFE000000u;
    return (int)value >> 26;
}
