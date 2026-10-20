#pragma force_active on
extern "C" unsigned int fn_27_8CDF4(unsigned char *p)
{
    unsigned char *a = *reinterpret_cast<unsigned char **>(p + 0x60);
    unsigned char *b = *reinterpret_cast<unsigned char **>(a + 0xD8);
    return *reinterpret_cast<unsigned int *>(b + 0x38);
}
