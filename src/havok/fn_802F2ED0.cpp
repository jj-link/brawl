#pragma force_active on

extern "C" {
double fn_80400B34(double);
float fn_802F2ED0(float);
extern const float lbl_805A4504;
extern const float lbl_805A44F8;
extern const float lbl_805A452C;
extern const float lbl_805A4530;
}

float fn_802F2ED0(float x) {
    if ((float)__fabs(x) >= lbl_805A4504) {
        return (x > lbl_805A44F8) ? lbl_805A452C : lbl_805A4530;
    }
    return (float)fn_80400B34(x);
}
