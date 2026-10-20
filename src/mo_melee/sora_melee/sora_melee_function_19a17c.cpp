#pragma force_active on
extern "C" int fn_27_19A17C(const unsigned int *p)
{
    unsigned int x = *(const unsigned int *)((const char *)p + 8);
    x = (x << 10) & 0xFC000000;
    return (int)x >> 27;
}
