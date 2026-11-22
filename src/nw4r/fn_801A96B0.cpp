#pragma force_active on

extern "C" {
extern const float lbl_805A33B8;
extern const float lbl_805A33BC;
extern const float lbl_805A33C0;

void fn_80162384(float*, float*, float);
}

inline void SinCos(float angle, float* s, float* c) {
    fn_80162384(s, c, lbl_805A33C0 * angle);
}

extern "C" void fn_801A96B0(float* out, const float* in) {
    float s, c;
    SinCos(in[2], &s, &c);

    float sy;
    float x = in[3];

    float s0;
    float c0 = c;
    sy = in[1];
    s0 = s;
    float sx = in[0];
    float z = lbl_805A33B8;
    float xc = sx * c0;
    float xs = sx * s0;
    float yc = sy * c0;
    float ys = sy * s0;

    out[0] = xc;
    out[1] = -xs;
    out[2] = z;
    out[3] = (xs - xc * x) - xs * in[4];
    out[4] = ys;
    out[5] = yc;
    out[6] = z;
    out[7] = lbl_805A33BC + ((-yc - ys * x) + yc * in[4]);
}
