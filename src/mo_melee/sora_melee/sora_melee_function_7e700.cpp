#pragma force_active on
struct Vec2Zero {
    float x;
    float y;
};

extern const float lbl_27_rodata_B70;

extern "C" {
Vec2Zero fn_27_7E700() {
    Vec2Zero v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
}
