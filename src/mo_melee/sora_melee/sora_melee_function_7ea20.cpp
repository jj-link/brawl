#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Vec2 {
    float x;
    float y;
};

extern "C" {
Vec2 fn_27_7EA20() {
    Vec2 v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
}
