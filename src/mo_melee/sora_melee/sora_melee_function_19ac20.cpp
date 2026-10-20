#pragma force_active on
extern "C" int fn_27_19AC20(const void *p)
{
    unsigned int value = *(const unsigned int *)((const char *)p + 8);
    value = (value << 2) & 0xE0000000;
    return (int)value >> 30;
}
