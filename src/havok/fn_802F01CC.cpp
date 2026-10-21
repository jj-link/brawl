#pragma force_active on
extern "C" {
extern const float lbl_805A44BC;
extern const float lbl_805A44C0;

void fn_802F01CC(float* p, float scale) {
    float a = lbl_805A44BC * scale;
    float b = lbl_805A44C0 * scale;
    p[12] = a;
    p[13] = a;
    p[14] = a;
    p[15] = a;
    p[16] = b;
    p[17] = b;
    p[18] = b;
    p[19] = b;
}
}
