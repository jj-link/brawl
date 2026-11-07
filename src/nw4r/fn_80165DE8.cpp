#pragma force_active on
extern "C" {
float fn_801ED1C4(int, int);
double fn_80400D94(float);
extern const float lbl_805A2C88;
extern const float lbl_805A2C94;
}
extern "C" float fn_80165DE8(int a, int b, float x, float y, float z, float w) {
    float range = x - y;
    float value = (float)fn_80400D94(fn_801ED1C4(b, a)) - y;
    float low = range * w;
    float high = range * z;
    if (low > value) return lbl_805A2C94;
    if (high < value) return lbl_805A2C88;
    float diff = high - low;
    if (lbl_805A2C88 == diff) return lbl_805A2C88;
    return lbl_805A2C94 - (value - low) / diff;
}