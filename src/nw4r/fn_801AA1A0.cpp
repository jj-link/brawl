#pragma force_active on
extern "C" {
extern const float lbl_805A33C8;
extern const float lbl_805A33CC;
extern const float lbl_805A33D4;
void fn_80162384(float*, float*, float);
void fn_801AA1A0(float* out, const float* in) {
    float s, c;
    float scaled = in[2];
    scaled = lbl_805A33D4 * scaled;
    fn_80162384(&s, &c, scaled);
    float y, x, half, z;
    out[0] = c;
    out[1] = s;
    z = lbl_805A33C8;
    half = lbl_805A33CC;
    x = half + in[3];
    out[2] = z;
    y = in[4] - half;
    out[3] = half + (-c * x + s * y);
    out[4] = -s;
    out[5] = c;
    out[6] = z;
    out[7] = half + (s * x + c * y);
}
}