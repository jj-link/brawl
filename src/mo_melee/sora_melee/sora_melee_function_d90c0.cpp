#pragma force_active on
extern "C" void *fn_27_D90C0(void *object, int index)
{
    int offset = *(int *)((char *)object + 8) >> 28;
    int result = offset + index;

    if (result >= 7)
        result -= 7;

    return (char *)object + 12 + result * 20;
}
