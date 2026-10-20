#pragma force_active on
extern "C" void *fn_27_50D74(void *p, int index)
{
    int shift = *(int *)((char *)p + 0x18) >> 23;
    int sum = shift + index;

    if (sum >= 0xFF)
        sum -= 0xFF;

    return (char *)p + sum * 0xC + 0x1C;
}
