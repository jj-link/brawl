#pragma force_active on
extern "C" void *fn_27_1CFA20(void *self, int idx)
{
    char *p = (char *)self;
    int v = *(int *)(p + 8);
    int i = (v >> 26) + idx;
    if (i >= 18) {
        i -= 18;
    }
    return p + 12 + i * 12;
}
