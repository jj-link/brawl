#pragma force_active on
extern "C" void *fn_27_1B07B4(char *self, int idx)
{
    int v = *(int *)(self + 8);
    int i = (v >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return self + i * 0x24 + 0xC;
}
