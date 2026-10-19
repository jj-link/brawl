#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

extern "C" const float lbl_118_rodata_C;
extern "C" void fn_118_C3EC(void*, const Vec2f*);

extern "C" void fn_118_C3B4(void* object) {
    Vec2f tmp;
    tmp.x = lbl_118_rodata_C;
    tmp.y = lbl_118_rodata_C;
    fn_118_C3EC(static_cast<unsigned char*>(object) + 0x8, &tmp);
}
