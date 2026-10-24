#pragma force_active on

extern const float lbl_805A33A4;

extern "C" void fn_801A8FA0(float* v, const float* m) {
    v[0] = v[0] * m[0];
    v[1] = v[1] * m[0];
    v[2] = v[2] * m[0];
    v[3] = m[0] * (v[3] - m[3]);
    v[4] = v[4] * m[1];
    v[5] = v[5] * m[1];
    v[6] = v[6] * m[1];
    v[7] = (m[1] * (v[7] + m[4] - lbl_805A33A4)) + lbl_805A33A4;
}
