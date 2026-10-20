#pragma force_active on
typedef int s32;

extern "C" float fn_27_3A037C(char *base, s32 unused, s32 a, s32 b)
{
    char *p = base + ((a - *(s32 *)(base + 0x10)) << 2);
    float *tbl = *(float **)(p + 0x18);
    return tbl[b];
}
