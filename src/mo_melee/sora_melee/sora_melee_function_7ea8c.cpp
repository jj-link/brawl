#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

extern const float lbl_27_rodata_B70;

extern "C" {
Vec2f fn_27_7EA8C(void)
{
    Vec2f v;
    v.x = lbl_27_rodata_B70;
    v.y = lbl_27_rodata_B70;
    return v;
}
}
