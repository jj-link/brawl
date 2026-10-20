#pragma force_active on
extern "C" int fn_27_1A152C(const unsigned int* p)
{
    unsigned int value = p[2] & 0x00F80000;
    value = (value << 8) & 0xF8000000;
    return (int)value >> 28;
}
