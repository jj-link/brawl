#pragma force_active on
extern "C" int fn_27_3902E8(const unsigned int *p)
{
    int value = (int)(p[2] << 3);
    value &= (int)0xF0000000u;
    return value >> 29;
}
