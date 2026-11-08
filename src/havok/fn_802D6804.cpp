#pragma force_active on
extern "C" void fn_802878F0(float *out, void *m, float *v);

extern "C" void fn_802D6804(float *a, void *m, float *out, float r)
{
    float rad[4] __attribute__((aligned(16)));
    float c0[4] __attribute__((aligned(16)));
    float c1[4] __attribute__((aligned(16)));
    float c2[4] __attribute__((aligned(16)));
    float *p = a + 4;
    float t = r + a[3];

    rad[0] = t;
    rad[1] = t;
    rad[2] = t;
    rad[3] = t;

    fn_802878F0(c0, m, p);
    float *q = a + 8;
    fn_802878F0(c1, m, q);
    float *s = a + 12;
    fn_802878F0(c2, m, s);

    out[0] = (c0[0] < c1[0]) ? c0[0] : c1[0];
    out[1] = (c0[1] < c1[1]) ? c0[1] : c1[1];
    out[2] = (c0[2] < c1[2]) ? c0[2] : c1[2];
    out[3] = (c0[3] < c1[3]) ? c0[3] : c1[3];
    out[4] = (c0[0] > c1[0]) ? c0[0] : c1[0];
    out[5] = (c0[1] > c1[1]) ? c0[1] : c1[1];
    out[6] = (c0[2] > c1[2]) ? c0[2] : c1[2];
    out[7] = (c0[3] > c1[3]) ? c0[3] : c1[3];

    out[0] = (out[0] < c2[0]) ? out[0] : c2[0];
    out[1] = (out[1] < c2[1]) ? out[1] : c2[1];
    out[2] = (out[2] < c2[2]) ? out[2] : c2[2];
    out[3] = (out[3] < c2[3]) ? out[3] : c2[3];
    out[4] = (out[4] > c2[0]) ? out[4] : c2[0];
    out[5] = (out[5] > c2[1]) ? out[5] : c2[1];
    out[6] = (out[6] > c2[2]) ? out[6] : c2[2];
    out[7] = (out[7] > c2[3]) ? out[7] : c2[3];

    out[0] = out[0] - rad[0];
    out[1] = out[1] - rad[1];
    out[2] = out[2] - rad[2];
    out[3] = out[3] - rad[3];
    out[4] = out[4] + rad[0];
    out[5] = out[5] + rad[1];
    out[6] = out[6] + rad[2];
    out[7] = out[7] + rad[3];
}
