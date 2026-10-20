#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

extern const float lbl_27_rodata_B70;
extern const float lbl_27_rodata_B74;

extern "C" {
Vec2 fn_27_7EC18(void)
{
    Vec2 v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B74;
    return v;
}
}
