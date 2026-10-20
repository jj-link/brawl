#pragma force_active on
extern "C" int fn_27_D32CC(const unsigned int *p)
{
    unsigned int value = *(const unsigned int *)((const char *)p + 8);
    value = (value << 8) & 0xF8000000;
    return (int)value >> 28;
}
