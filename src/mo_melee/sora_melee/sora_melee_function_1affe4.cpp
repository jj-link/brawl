#pragma force_active on
extern "C" void *fn_27_1AFFE4(void *p, int idx)
{
    int t = *(int *)((char *)p + 8);
    int n = (t >> 26) + idx;
    if (n >= 0x12) {
        n -= 0x12;
    }
    return (char *)p + (n << 4) + 12;
}
