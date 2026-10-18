#pragma force_active on
extern "C" int fn_48_1060(char *self, float *out)
{
    float *p = (float *)(self + 0x2b8);
    out[0] = p[0];
    out[1] = p[1];
    out[2] = p[2];
    return 1;
}
