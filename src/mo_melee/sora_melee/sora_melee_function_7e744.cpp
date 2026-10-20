#pragma force_active on
extern const float lbl_27_rodata_B70;

typedef union {
    struct {
        float x;
        float y;
    } f;
    unsigned long long u;
} FloatPairBits;

extern "C" unsigned long long fn_27_7E744(void)
{
    FloatPairBits v;
    v.f.x = lbl_27_rodata_B70;
    v.f.y = lbl_27_rodata_B70;
    return v.u;
}
