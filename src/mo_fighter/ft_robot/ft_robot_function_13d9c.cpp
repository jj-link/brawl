#pragma force_active on
typedef unsigned long long u64;
typedef unsigned int u32;

extern "C" const float lbl_120_rodata_80;

union FloatPair {
    struct { float a, b; } f;
    struct { u32 a, b; } w;
    u64 packed;
};

extern "C" u64 fn_120_13D9C(void) {
    FloatPair result;
    result.f.a = lbl_120_rodata_80;
    result.f.b = lbl_120_rodata_80;
    return result.packed;
}
