#pragma force_active on
extern "C" {
extern const float lbl_805A2FC4;
float fn_801622A0();

float fn_80179500(float farg0) {
    if (farg0 <= lbl_805A2FC4) {
        return lbl_805A2FC4;
    }
    return farg0 * fn_801622A0();
}
}
