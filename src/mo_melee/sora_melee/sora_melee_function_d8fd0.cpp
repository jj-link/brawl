#pragma force_active on
extern "C" void *fn_27_D8FD0(void *p, int index)
{
    int shifted = *(int *)((char *)p + 8) >> 30;
    int adjusted = shifted + index;
    if (adjusted >= 1)
        adjusted--;
    return (char *)p + adjusted * 0xA0 + 0xC;
}
