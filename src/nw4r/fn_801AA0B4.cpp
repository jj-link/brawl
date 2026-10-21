#pragma force_active on
extern float lbl_805A33C8;
extern float lbl_805A33D0;

extern "C" {
void fn_801AA0B4(float* out, const float* in) {
    float a = in[3];
    float na = -a;
    float zero = lbl_805A33C8;
    float one = lbl_805A33D0;
    out[0] = one;
    out[1] = zero;
    out[2] = zero;
    out[3] = na;
    out[4] = zero;
    out[5] = one;
    out[6] = zero;
    out[7] = in[4];
}
}
