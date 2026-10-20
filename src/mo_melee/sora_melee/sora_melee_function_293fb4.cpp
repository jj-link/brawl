#pragma force_active on
extern "C" char *fn_27_293FB4(char *p, int x)
{
    int v = (*(int *)(p + 0x18) >> 27) + x;
    if (v >= 9) {
        v -= 9;
    }
    return p + v * 12 + 0x1c;
}
