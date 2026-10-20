#pragma force_active on
extern "C" void *fn_27_1D0AA8(void *object, int index)
{
    int count = *(int *)((char *)object + 8) >> 29;
    int adjusted = count + index;
    if (adjusted >= 2)
        adjusted -= 2;
    return (char *)object + adjusted * 12 + 12;
}
