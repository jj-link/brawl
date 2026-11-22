#pragma force_active on
extern "C" {
extern const float lbl_805A33C8, lbl_805A33D0, lbl_805A33D4, lbl_805A33D8;
void fn_80162384(float*, float*, float);
void fn_801AA0EC(float* out, const float* in) {
    float spC, sp8;
    float scaled = in[2];
    scaled = lbl_805A33D4 * scaled;
    fn_80162384(&spC, &sp8, scaled);
    float y = in[0];
    float f5 = y * sp8;
    float f6 = y * spC;
    float f4 = in[1] * sp8;
    float f7 = in[1] * spC;
    out[0] = f5;
    out[1] = f6;
    out[2] = lbl_805A33C8;
    out[3] = lbl_805A33D8 * ((f5 + f6) - lbl_805A33D0);
    out[4] = -f7;
    out[5] = f4;
    out[6] = lbl_805A33C8;
    out[7] = lbl_805A33D8 * ((-f7 + f4) - lbl_805A33D0);
}
}