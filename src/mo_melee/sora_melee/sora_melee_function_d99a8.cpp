#pragma force_active on
extern "C" void *fn_27_D99A8(void *p, int index)
{
    int flags = *(int *)((char *)p + 8);
    int adjusted = (flags >> 29) + index;
    if (adjusted >= 2)
        adjusted -= 2;
    return (char *)p + adjusted * 0x78 + 0x0C;
}
