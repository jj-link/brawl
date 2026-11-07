#pragma force_active on
extern "C" {
extern const float lbl_805A43C4;
}
extern "C" void fn_802E4998(float* p_struct, float* p_out)
{
    float arr[4] __attribute__((aligned(16)));
    float zero = lbl_805A43C4;
    float x = p_struct[0x34];
    float y = p_struct[0x35];
    float z = p_struct[0x36];
    arr[3] = zero;
    p_out[1] = zero;
    p_out[2] = zero;
    p_out[3] = zero;
    p_out[4] = zero;
    p_out[6] = zero;
    p_out[7] = zero;
    p_out[8] = zero;
    p_out[9] = zero;
    p_out[11] = zero;
    p_out[0] = x;
    p_out[5] = y;
    p_out[10] = z;
    arr[2] = zero;
    arr[1] = zero;
    arr[0] = zero;
}