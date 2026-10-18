#pragma force_active on
extern const float lbl_27_rodata_B70;

struct FloatPair {
    float x;
    float y;
};

struct FloatPairSource {
    virtual void unused0() { }
    virtual void unused1() { }
    virtual FloatPair get() = 0;
};

struct Float3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_27_7FCF8(Float3* out, FloatPairSource* source) {
    FloatPair value = source->get();
    out->x = value.x;
    out->y = value.y;
    out->z = lbl_27_rodata_B70;
}
