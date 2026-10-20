#pragma force_active on
extern "C" void *fn_27_D9778(void *base, int index)
{
    int offset = *(int *)((char *)base + 8) >> 30;
    int adjusted = offset + index;

    if (adjusted >= 1)
        adjusted -= 1;

    return (char *)base + adjusted * 0x60 + 0x0C;
}
