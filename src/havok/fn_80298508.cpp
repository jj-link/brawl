#pragma force_active on
struct Vec8
{
    float f[8];
};

extern "C" void fn_80298508(Vec8 *out, const Vec8 *a, const Vec8 *b)
{
    out->f[0] = a->f[0] - b->f[0];
    out->f[1] = a->f[1] - b->f[1];
    out->f[2] = a->f[2] - b->f[2];
    out->f[3] = a->f[3] - b->f[3];
    out->f[4] = a->f[4] - b->f[4];
    out->f[5] = a->f[5] - b->f[5];
    out->f[6] = a->f[6] - b->f[6];
    out->f[7] = a->f[7] - b->f[7];
}
