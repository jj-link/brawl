#pragma force_active on
extern "C" void *fn_27_4CB98(void *object, int index)
{
    int value = *(int *)((char *)object + 8) >> 30;
    int sum = value + index;

    if (sum >= 1)
        sum -= 1;

    return (char *)object + sum * 0x78 + 0x0C;
}
