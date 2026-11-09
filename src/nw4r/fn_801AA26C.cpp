#pragma force_active on
extern "C" {
extern const float lbl_805A33C8;
extern const float lbl_805A33CC;
void fn_801AA26C(float *out, const float *in) {
    out[0] = in[0];
    out[1] = lbl_805A33C8;
    out[2] = lbl_805A33C8;
    out[4] = lbl_805A33C8;
    out[3] = lbl_805A33CC + -in[0] * (lbl_805A33CC + in[3]);
    out[5] = in[1];
    out[6] = lbl_805A33C8;
    out[7] = lbl_805A33CC + in[1] * (in[4] - lbl_805A33CC);
}
}
