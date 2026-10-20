#pragma force_active on
extern "C" void *fn_27_C4E64(char *p, int n)
{
    int idx = (*(int *)(p + 0x18) >> 30) + n;
    if (idx >= 1) {
        idx--;
    }
    return p + idx * 12 + 0x1c;
}
