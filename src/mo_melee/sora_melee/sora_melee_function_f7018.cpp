#pragma force_active on
extern "C" void *fn_27_F7018(int *p, int index)
{
    int value = (p[6] >> 30) + index;
    if (value >= 1)
        value -= 1;
    return (char *)p + value * 12 + 0x1C;
}
