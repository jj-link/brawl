#pragma force_active on
extern "C" {
extern const float lbl_805A43C0;
extern const float lbl_805A43C4;
}
extern "C" void fn_802E48F0(float *a, float *b)
{
    __declspec(align(16)) float tmp[4];
    float zero = lbl_805A43C4;
    float d0 = a[52];
    float d1;
    float d2;
    d2 = a[53];
    d1 = a[54];
    float one = lbl_805A43C0;
    float q0 = one / d0;
    float q1 = one / d2;
    float q2 = one / d1;
    b[1] = zero;
    b[2] = zero;
    b[3] = zero;
    b[4] = zero;
    b[6] = zero;
    b[7] = zero;
    b[8] = zero;
    b[9] = zero;
    b[11] = zero;
    b[0] = q0;
    b[5] = q1;
    b[10] = q2;
    tmp[3] = zero;
    tmp[2] = zero;
    tmp[1] = zero;
    tmp[0] = zero;
}