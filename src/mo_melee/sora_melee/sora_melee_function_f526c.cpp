#pragma force_active on
extern "C" void *fn_27_F526C(void *object, int index)
{
    int offset = *(int *)((char *)object + 0x18) >> 29;
    int sum = offset + index;

    if (sum >= 3)
        sum -= 3;

    return (char *)object + sum * 12 + 0x1C;
}
