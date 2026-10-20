#pragma force_active on
extern "C" void *fn_27_FE7AC(void *p, int index)
{
    int offset = *(int *)((char *)p + 8) >> 29;
    int adjusted = offset + index;
    if (adjusted >= 3)
        adjusted -= 3;
    return (char *)p + adjusted * 12 + 12;
}
