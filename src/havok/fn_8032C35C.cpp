#pragma force_active on
extern "C" {
extern const float lbl_805A4848;
extern const float lbl_805A484C;
extern const float lbl_805A4854;
}
static inline float multiply(float a, float b) { return a * b; }
extern "C" int fn_8032C35C(float* p, float radius, float mass) {
    float arr[4] __attribute__((aligned(16)));
    float zero = lbl_805A4848;
    if (mass <= zero) return 1;
    if (radius <= zero) return 1;
    float inertia = lbl_805A484C * (radius * (mass * radius));
    p[8] = zero;
    p[13] = zero;
    p[18] = zero;
    arr[3] = zero;
    arr[2] = zero;
    arr[1] = zero;
    arr[0] = zero;
    p[9] = zero;
    p[10] = zero;
    p[11] = zero;
    p[12] = zero;
    p[14] = zero;
    p[15] = zero;
    p[16] = zero;
    p[17] = zero;
    p[19] = zero;
    p[8] = inertia;
    p[13] = inertia;
    p[18] = inertia;
    p[7] = zero;
    p[6] = zero;
    p[5] = zero;
    p[4] = zero;
    p[0] = radius * multiply(lbl_805A4854 * radius, radius);
    p[1] = mass;
    return 0;
}