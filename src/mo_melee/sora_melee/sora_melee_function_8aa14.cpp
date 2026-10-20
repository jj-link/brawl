#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

extern const float lbl_27_rodata_BC0;

extern "C" {
Vec2f fn_27_8AA14() {
    Vec2f tmp;
    tmp.x = lbl_27_rodata_BC0;
    tmp.y = lbl_27_rodata_BC0;
    return tmp;
}
}
