#pragma force_active on
extern "C" void *fn_27_F0D08(void *p, int index)
{
    int offset = *(int *)((char *)p + 0x18) >> 30;
    int value = offset + index;
    if (value >= 1)
        value -= 1;
    return (char *)p + value * 12 + 0x1C;
}
