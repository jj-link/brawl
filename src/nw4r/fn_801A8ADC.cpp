#pragma force_active on
#pragma fp_contract off

extern const float lbl_805A33A4;

extern "C" void fn_801A8ADC(float* m, const float* v)
{
    m[0] = m[0] * v[0];
    m[1] = m[1] * v[0];
    m[2] = m[2] * v[0];
    m[3] = m[3] * v[0];
    m[4] = m[4] * v[1];
    m[5] = m[5] * v[1];
    m[6] = m[6] * v[1];
    m[7] = (lbl_805A33A4 + m[7] * v[1]) - v[1];
}
