#pragma force_active on
extern "C" int *fn_27_10E7B8(int *base, int index)
{
    int offset = base[6] >> 27;
    int sum = offset + index;
    if (sum < 8)
        goto done;

    sum -= 8;

done:
    return (int *)((char *)base + sum * 12 + 0x1C);
}
