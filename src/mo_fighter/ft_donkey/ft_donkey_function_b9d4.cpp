#pragma force_active on
extern "C" const float lbl_92_rodata_8;

struct Vec2fLocal {
    float x;
    float y;
};

extern "C" void fn_92_BA0C(Vec2fLocal* dst, const Vec2fLocal* src);

extern "C" void fn_92_B9D4(Vec2fLocal* object) {
    Vec2fLocal value;
    value.x = lbl_92_rodata_8;
    value.y = lbl_92_rodata_8;
    fn_92_BA0C(reinterpret_cast<Vec2fLocal*>(
                   reinterpret_cast<char*>(object) + 8),
               &value);
}
