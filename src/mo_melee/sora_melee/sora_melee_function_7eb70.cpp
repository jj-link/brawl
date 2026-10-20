#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Vec2F {
    float x;
    float y;
};

extern "C" {
Vec2F fn_27_7EB70() {
    Vec2F v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
}
