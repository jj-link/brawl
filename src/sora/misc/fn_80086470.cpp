#pragma force_active on

extern "C" {
float randf__Fv();
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;
extern const float lbl_805A1C14;
}

struct Offset48 {
    char pad[0x48];
    float value;
};

extern "C" float fn_80086470(Offset48* ptr, float a, float b, float c) {
    if (lbl_805A1BBC * randf__Fv() > lbl_805A1C14) {
        if (a < lbl_805A1BB8) {
            return a - ptr->value * (b * (lbl_805A1BBC * randf__Fv()));
        }
        return a + ptr->value * (c * (lbl_805A1BBC * randf__Fv()));
    }
    return lbl_805A1BB8;
}