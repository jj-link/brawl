#pragma force_active on

extern "C" void fn_80304D50(float* p, float* v, int* out) {
    float a = p[0];
    int r = 0;
    float f = *v;
    if (a > f || p[1] > f || p[2] > f) {
        r = 1;
    }
    *out = r;
}
