#pragma force_active on
extern "C" int fn_27_FEC50(const unsigned int *p)
{
    unsigned int value = *(const unsigned int *)((const char *)p + 8);
    value = (value << 7) & 0xFF000000u;
    return (int)((signed int)value >> 25);
}
