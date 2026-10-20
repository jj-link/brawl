#pragma force_active on
extern "C" void *fn_27_1CCA98(void *p, int i) {
    int n = (*(int *)((char *)p + 0x18) >> 29) + i;
    if (n >= 2)
        n -= 2;
    return (char *)p + 0x1C + n * 12;
}
