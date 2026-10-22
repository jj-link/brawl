#pragma force_active on
extern const float lbl_805A33C8;
extern const float lbl_805A33CC;
extern const float lbl_805A33D0;
extern "C" void fn_801A9FC0(float* out, const float* in) {
    out[0] = in[0];
    out[1] = lbl_805A33C8;
    out[2] = lbl_805A33C8;
    out[3] = lbl_805A33CC * (lbl_805A33D0 - in[0]);
    out[4] = lbl_805A33C8;
    out[5] = in[1];
    out[6] = lbl_805A33C8;
    out[7] = lbl_805A33CC * (lbl_805A33D0 - in[1]);
}
