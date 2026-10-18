#pragma force_active on
struct ExtendParam {
    float floats[4];
    int ints[3];
};

extern "C" {
extern ExtendParam lbl_27_bss_2BC;
}

extern "C" ExtendParam* fn_27_7DC50() {
    return &lbl_27_bss_2BC;
}
