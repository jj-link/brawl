#pragma force_active on
extern "C" int *fn_27_FEBFC(int *base, int index)
{
    int offset = base[2] >> 30;
    int sum = offset + index;
    if (sum >= 1)
        --sum;
    return (int *)((char *)base + sum * 12 + 12);
}
