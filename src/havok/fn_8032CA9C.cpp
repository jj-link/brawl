#pragma force_active on
extern "C" {
extern const float lbl_805A4848;
extern const float lbl_805A4850;
}

extern "C" void fn_8032CA9C(float *p)
{
    float arr[4] __attribute__((aligned(16)));
    float zero = lbl_805A4848;
    float one = lbl_805A4850;
    p[0] = zero;
    p[5] = zero;
    p[10] = zero;
    p[1] = zero;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    p[6] = zero;
    p[7] = zero;
    p[8] = zero;
    p[9] = zero;
    p[11] = zero;
    arr[3] = zero;
    arr[2] = zero;
    arr[1] = zero;
    arr[0] = zero;
    p[0] = one;
    p[5] = one;
    p[10] = one;
    p[15] = zero;
    p[14] = zero;
    p[13] = zero;
    p[12] = zero;
}
