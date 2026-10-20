#pragma force_active on
extern "C" int *fn_27_FE91C(int *base, int index)
{
    int offset = base[2] >> 28;
    int result = offset + index;
    if (result >= 4)
        result -= 4;
    return (int *)((char *)base + result * 12 + 12);
}
