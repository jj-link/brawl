#pragma force_active on

extern "C" {

extern const float lbl_805A33C8;
extern const float lbl_805A33D0;
extern const float lbl_805A33D4;
extern const float lbl_805A33D8;

void fn_80162384(float*, float*, float);

void fn_801AA008(float* out, const float* in) {
    float spC;
    float sp8;
    float scaled = in[2];
    scaled = lbl_805A33D4 * scaled;

    fn_80162384(&spC, &sp8, scaled);

    out[0] = sp8;
    out[1] = spC;
    out[2] = lbl_805A33C8;
    out[3] = lbl_805A33D8 * ((sp8 + spC) - lbl_805A33D0);
    out[4] = -spC;
    out[5] = sp8;
    out[6] = lbl_805A33C8;
    out[7] = lbl_805A33D8 * ((-spC + sp8) - lbl_805A33D0);
}

}
