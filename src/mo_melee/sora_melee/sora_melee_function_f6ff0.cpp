#pragma force_active on
extern "C" void *fn_27_F6FF0(void *p, int index)
{
    int count = *(int *)((char *)p + 0x18) >> 30;
    int adjusted = count + index;
    if (adjusted >= 1)
        adjusted--;
    return (char *)p + adjusted * 12 + 0x1C;
}
