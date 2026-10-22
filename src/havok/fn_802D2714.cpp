#pragma force_active on

extern "C" {
int fn_80282148(float);
extern const float lbl_805A40D8;
extern const float lbl_805A40DC;
extern const float lbl_805A40E0;
extern const float lbl_805A40E4;
}

extern "C" float fn_802D2714(void) {
    float x = lbl_805A40D8;
    while (x < lbl_805A40E0) {
        if (fn_80282148(x) != 0) {
            return x;
        }
        x += lbl_805A40DC;
    }
    return lbl_805A40E4;
}
