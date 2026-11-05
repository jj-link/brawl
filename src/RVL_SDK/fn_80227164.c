#pragma force_active on
extern double fn_80400D94(float);
extern const double lbl_805A3A08;
extern const float lbl_805A39E8;

void fn_80227164(float* out, int a, int b, int c, int d) {
    float fa = (float)a;
    float fb = (float)b;
    float fc = (float)c;
    float fd = (float)d;
    float len = (float)fn_80400D94(fa * fa + fb * fb);
    if (len <= fc) {
        out[1] = lbl_805A39E8;
        out[0] = lbl_805A39E8;
    } else if (len >= fd) {
        out[0] = fa / len;
        out[1] = fb / len;
    } else {
        float t = (len - fc) / (fd - fc) / len;
        out[0] = fa * t;
        out[1] = fb * t;
    }
}