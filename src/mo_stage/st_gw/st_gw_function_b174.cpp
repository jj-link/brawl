#pragma force_active on
extern "C" void *fn_63_B174(void *self, int index)
{
    int n = (*(int *)((char *)self + 8) >> 28) + index;
    if (n >= 7) {
        n -= 7;
    }
    return (char *)self + (n << 3) + 0xC;
}
