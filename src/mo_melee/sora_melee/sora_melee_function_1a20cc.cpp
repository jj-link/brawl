#pragma force_active on
extern "C" int fn_27_1A20CC(const unsigned int *p)
{
    unsigned int value = *reinterpret_cast<const unsigned int *>(
        reinterpret_cast<const char *>(p) + 8);
    value = (value << 10) & 0xFC000000u;
    return static_cast<int>(value) >> 27;
}
