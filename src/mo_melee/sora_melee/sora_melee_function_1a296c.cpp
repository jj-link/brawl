#pragma force_active on
extern "C" int fn_27_1A296C(const unsigned int *p)
{
    unsigned int value = *reinterpret_cast<const unsigned int *>(
        reinterpret_cast<const char *>(p) + 8);
    value = (value << 4) & 0xF8000000u;
    return (int)value >> 28;
}
