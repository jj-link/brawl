#pragma force_active on
extern "C" void *fn_27_D8F30(char *p, int n)
{
    int v = *(int *)(p + 8) >> 27;
    int idx = v + n;
    if (idx >= 10) {
        idx -= 10;
    }
    return p + idx * 4 + 12;
}
