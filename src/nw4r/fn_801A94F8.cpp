#pragma force_active on
extern "C" {
extern const float lbl_805A33B8;
extern const float lbl_805A33BC;
extern const float lbl_805A33C0;
void fn_80162384(float*, float*, float);
void fn_801A94F8(float* out, const float* in) {
    float spC, sp8;
    float scaled = in[2];
    scaled = lbl_805A33C0 * scaled;
    fn_80162384(&spC, &sp8, scaled);
    float c = sp8;
    float y = in[1];
    float x = in[0];
    float s = spC;
    float f5 = x * c;
    float f6 = x * s;
    float f7 = y * c;
    float f4 = y * s;
    out[0] = f5;
    out[1] = -f6;
    out[2] = lbl_805A33B8;
    out[3] = f6;
    out[4] = f4;
    out[5] = f7;
    out[6] = lbl_805A33B8;
    out[7] = lbl_805A33BC + -f7;
}
}