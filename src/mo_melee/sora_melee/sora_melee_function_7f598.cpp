#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Vec2f {
    float x;
    float y;
};

extern "C" Vec2f fn_27_7F598() {
    Vec2f v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
