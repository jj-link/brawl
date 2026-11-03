#pragma force_active on
#pragma fp_contract on
extern float lbl_805A47A0;
extern "C" void fn_803248DC(float* out, const float* a, const float* b, float t) {
    float s = lbl_805A47A0 - t;
    float x = s * a[0] + t * b[0];
    float y = s * a[1] + t * b[1];
    float z = s * a[2] + t * b[2];
    float w = s * a[3] + t * b[3];
    out[0] = x;
    out[1] = y;
    out[2] = z;
    out[3] = w;
}