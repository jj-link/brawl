#pragma force_active on
extern "C" void *fn_27_122AE4(void *base, int index)
{
    int field = *(int *)((char *)base + 8) >> 28;
    int adjusted = field + index;

    if (adjusted >= 4)
        adjusted -= 4;

    return (char *)base + adjusted * 0x18 + 0x0C;
}
