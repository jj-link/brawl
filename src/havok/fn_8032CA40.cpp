#pragma force_active on

extern "C" {
double fn_80400B30(double);
extern const float lbl_805A4848;
extern const float lbl_805A4850;
extern const float lbl_805A4864;
}

struct hkMath {
    static float acos(float x);
};

float hkMath::acos(float x) {
    float v;
    if ((float)__fabs(x) >= lbl_805A4850) {
        v = (x > lbl_805A4848) ? lbl_805A4848 : lbl_805A4864;
        return v;
    }
    return (float)fn_80400B30(x);
}
