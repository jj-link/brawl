#pragma force_active on
extern "C" void *fn_27_D9098(void *base, int index)
{
    int value = *(int *)((char *)base + 8) >> 30;
    int adjusted = value + index;
    if (adjusted >= 1)
        adjusted -= 1;
    return (char *)base + adjusted * 0x68 + 0x0C;
}
