#pragma force_active on
extern "C" {
extern const float lbl_805A43D8;
extern const float lbl_805A43DC;
}

extern "C" void fn_802E5B50(float *p_struct, float *p_out)
{
    float arr[4] __attribute__((aligned(16)));
    float zero = lbl_805A43DC;
    float den = p_struct[0x34];
    float one = lbl_805A43D8;
    arr[3] = zero;
    float recip = one / den;
    p_out[1] = zero;
    p_out[2] = zero;
    p_out[3] = zero;
    p_out[4] = zero;
    p_out[6] = zero;
    p_out[7] = zero;
    p_out[8] = zero;
    p_out[9] = zero;
    p_out[11] = zero;
    p_out[0] = recip;
    p_out[5] = recip;
    p_out[10] = recip;
    arr[2] = zero;
    arr[1] = zero;
    arr[0] = zero;
}