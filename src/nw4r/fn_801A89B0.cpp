#pragma force_active on
extern "C" {
extern const float lbl_805A33A0;
extern const float lbl_805A33A4;

void fn_801A89B0(float* out, const float* in) {
    out[0] = in[0];
    out[1] = lbl_805A33A0;
    out[2] = lbl_805A33A0;
    out[3] = -in[0] * in[3];
    out[4] = lbl_805A33A0;
    out[5] = in[1];
    out[6] = lbl_805A33A0;
    out[7] = lbl_805A33A4 + in[1] * (in[4] - lbl_805A33A4);
}
}