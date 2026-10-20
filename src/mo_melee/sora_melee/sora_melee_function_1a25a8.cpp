#pragma force_active on
extern "C" int fn_27_1A25A8(const unsigned int *p)
{
    return (int)((*reinterpret_cast<const unsigned int *>(
        reinterpret_cast<const unsigned char *>(p) + 8) << 5) & 0xFC000000U) >> 27;
}
