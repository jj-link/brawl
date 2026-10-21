#pragma force_active on
extern "C" void fn_801119F8(char *self, float *out, unsigned short *idx)
{
    char *base = *(char **)(self + 0x10);
    char *p = base + idx[0] * 0x10;
    char *q = base + idx[1] * 0x10;
    out[0] = *(float *)(p + 0x8);
    out[1] = *(float *)(p + 0xC);
    out[2] = *(float *)(q + 0x8);
    out[3] = *(float *)(q + 0xC);
}
