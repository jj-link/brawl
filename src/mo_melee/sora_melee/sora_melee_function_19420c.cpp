#pragma force_active on
extern "C" int fn_27_19420C(const unsigned char *base, int index)
{
    signed char value = *(signed char *)((char *)base + index * 2 + 0x64);
    int below = -1 - value;
    int above = value + 1;
    return (below | above) >> 31 & 1;
}
