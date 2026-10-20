#pragma force_active on
extern "C" void *fn_27_1C1868(void *p, int index)
{
    int shifted = *(int *)((char *)p + 0x18) >> 27;
    int sum = shifted + index;

    if (sum >= 8)
        sum -= 8;

    return (char *)p + 0x1C + sum * 12;
}
