#pragma force_active on
extern "C" void *fn_27_3957EC(void *base, int index)
{
    int offset = *(int *)((char *)base + 8) >> 28;
    int result = offset + index;

    if (result >= 7)
        result -= 7;

    return (char *)base + result * 120 + 12;
}
