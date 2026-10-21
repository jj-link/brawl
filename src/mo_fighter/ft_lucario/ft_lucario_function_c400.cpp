#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

extern "C" const float lbl_118_rodata_C;
extern "C" const float lbl_118_rodata_10;
extern "C" void* fn_118_C3EC(void*, const Vec2f*);

extern "C" void fn_118_C400(void* object) {
    unsigned char* obj = static_cast<unsigned char*>(object);
    Vec2f a;
    a.x = lbl_118_rodata_C;
    a.y = lbl_118_rodata_C;

    fn_118_C3EC(obj + 0x8, static_cast<const Vec2f*>(fn_118_C3EC(obj + 0x10, static_cast<const Vec2f*>(fn_118_C3EC(obj + 0x20, &a)))));

    Vec2f b;
    b.x = lbl_118_rodata_10;
    b.y = lbl_118_rodata_10;
    fn_118_C3EC(obj + 0x18, static_cast<const Vec2f*>(fn_118_C3EC(obj + 0x28, &b)));
    obj[0x31] = 0;
    obj[0x30] = 0;
    obj[0x32] = 1;
}
