#pragma force_active on
extern "C" void *fn_27_1CFFE0(void *self, int index)
{
    int offset = *(int *)((char *)self + 8) >> 28;
    int sum = offset + index;
    if (sum >= 4)
        sum -= 4;
    return (char *)self + sum * 12 + 12;
}
