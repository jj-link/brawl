#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

extern "C" const float lbl_105_rodata_10;
extern "C" void fn_105_103C8(Vec2* dst, const Vec2* src);

extern "C" void fn_105_10390(Vec2* object) {
    Vec2 value;
    value.x = lbl_105_rodata_10;
    value.y = lbl_105_rodata_10;
    fn_105_103C8(object + 1, &value);
}
