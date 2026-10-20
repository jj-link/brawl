#pragma force_active on
extern "C" void *fn_40_30B80(void *base, int index)
{
    int shifted = *(int *)((char *)base + 8) >> 27;
    int sum = shifted + index;
    int adjusted = sum;

    if (sum >= 13)
        adjusted = sum - 13;

    return (char *)base + adjusted * 56 + 12;
}
