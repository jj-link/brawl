#pragma force_active on
extern "C" {
char *fn_27_1B0878(char *base, int idx)
{
    int t = *(int *)(base + 8) >> 29;
    int s = t + idx;
    int r = s >= 2 ? s - 2 : s;
    return base + 0xc + r * 0x2c;
}
}
