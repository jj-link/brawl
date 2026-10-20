#pragma force_active on
extern "C" int fn_47_4F18(const unsigned int *p)
{
    unsigned int value = *(const unsigned int *)((const char *)p + 8);
    value = (value << 4) & 0xF8000000;
    return (int)value >> 28;
}
