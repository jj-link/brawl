#pragma force_active on
extern "C" void *fn_27_D8F58(void *self, int index)
{
    int shifted = *(int *)((char *)self + 8) >> 27;
    int sum = shifted + index;
    if (sum >= 10)
        sum -= 10;
    return (char *)self + 12 + sum * 4;
}
