#pragma force_active on
extern "C" int fn_27_338784(char *self, int unused, int a, int b)
{
    int base = *(int *)(self + 0x14);
    int *tbl = *(int **)(self + ((a - base) << 2) + 0x2c);
    return tbl[b];
}
