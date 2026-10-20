#pragma force_active on
extern "C" void *fn_27_1E5B28(void *p, int index)
{
    int value = *(int *)((char *)p + 0x18);
    value = (value >> 30) + index;
    if (value >= 1)
        value -= 1;
    return (char *)p + value * 12 + 0x1C;
}
