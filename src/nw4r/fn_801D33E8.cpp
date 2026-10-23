#pragma force_active on

extern "C" {

extern const float lbl_805A3684;
extern const float lbl_805A3688;
extern const float lbl_805A368C;
extern const float lbl_8040B3F0[];

float fn_801D33E8(float farg0) {
    float v;
    if (farg0 > lbl_805A3684) {
        v = lbl_805A3684;
    } else if (farg0 < lbl_805A3688) {
        v = lbl_805A3688;
    } else {
        v = farg0;
    }
    return lbl_8040B3F0[(int)(lbl_805A368C * v) + 0x388];
}

}
