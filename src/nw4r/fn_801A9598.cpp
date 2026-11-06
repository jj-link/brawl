#pragma force_active on
extern "C" {
extern const float lbl_805A33B8;
extern const float lbl_805A33BC;
extern const float lbl_805A33C0;
void fn_80162384(float*, float*, float);
void fn_801A9598(float* out, const float* in) {
    float s, c;
    float scaled = in[2];
    scaled = lbl_805A33C0 * scaled;
    fn_80162384(&s, &c, scaled);
    out[0] = c;
    float y = in[4];
    float x = in[3];
    float z = lbl_805A33B8;
    out[1] = -s;
    out[2] = z;
    out[3] = (s - c * x) - s * y;
    out[4] = s;
    out[5] = c;
    out[6] = z;
    out[7] = lbl_805A33BC + ((-c - s * x) + c * y);
}
}
