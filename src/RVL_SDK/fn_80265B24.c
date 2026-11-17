#pragma force_active on

static inline void clamp_store(signed char *p, int v)
{
    int flag = 0;
    int r;
    if (v < 0x80 && v > -0x81) flag = 1;
    if (flag != 0) { r = v; } else { if (v > 0) r = 0x7f; else r = -0x80; }
    *p = r;
}

void fn_80265B24(int *arg0, signed char *arg1)
{
    int tmp[64];
    int *in;
    int *out;
    int i;

    in = arg0 + 24;
    out = tmp + 24;
    for (i = 0; i < 4; i++) {
        int a = in[0];
        int b = in[1];
        int c = in[2];
        int d = in[3];
        int t0 = a + c;
        int t1 = a - c;
        int m = ((b - d) * 0xB5) >> 8;
        int u = m + (b + d);
        out[0] = t0 + u;
        out[1] = t1 + m;
        out[2] = t1 - m;
        out[3] = t0 - u;
        in -= 8;
        out -= 8;
    }

    in = tmp + 3;
    for (i = 3; i >= 0; i--) {
        int a = in[0];
        int c = in[16];
        int b = in[8];
        int d = in[24];
        int t0 = a + c;
        int t1 = a - c;
        int m = ((b - d) * 0xB5) >> 8;
        int u = m + (b + d);
        signed char *o = arg1 + i;

        clamp_store(o, (t0 + u) >> 11);
        clamp_store(o + 8, (t1 + m) >> 11);
        clamp_store(o + 16, (t1 - m) >> 11);
        clamp_store(o + 24, (t0 - u) >> 11);
        in -= 1;
    }
}
