#pragma force_active on
extern const float lbl_40_rodata_2E8;

struct Vec2 {
    float x;
    float y;
};

extern "C" {
Vec2 fn_40_1DB74()
{
    Vec2 v;
    v.x = lbl_40_rodata_2E8;
    v.y = lbl_40_rodata_2E8;
    return v;
}
}
