#pragma force_active on
struct Vec2F {
    float x;
    float y;
};

extern const float lbl_27_rodata_B70;

extern "C" Vec2F fn_27_7E818() {
    Vec2F v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
