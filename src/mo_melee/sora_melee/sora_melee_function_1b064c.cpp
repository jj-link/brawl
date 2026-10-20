#pragma force_active on
extern "C" void *fn_27_1B064C(void *p, int index)
{
    int value = *(int *)((char *)p + 8) >> 27;
    int sum = value + index;
    if (sum >= 8)
        sum -= 8;
    return (char *)p + sum * 0x34 + 0xC;
}
