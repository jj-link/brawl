#pragma force_active on
extern "C" const float lbl_56_rodata_80;

struct Vec2 {
    float x;
    float y;
};

extern "C" {
Vec2 fn_56_54DC() {
    Vec2 v;
    v.x = lbl_56_rodata_80;
    v.y = lbl_56_rodata_80;
    return v;
}
}
