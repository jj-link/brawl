#pragma force_active on
extern "C" const float lbl_48_rodata_40;

union FloatPairBits {
    struct { float a, b; } f;
    struct { unsigned int first, second; } w;
    unsigned long long packed;
};

extern "C" unsigned long long fn_48_39A4(void) {
    FloatPairBits r;
    r.f.a = lbl_48_rodata_40;
    r.f.b = lbl_48_rodata_40;
    return r.packed;
}
