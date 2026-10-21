#pragma force_active on
struct Vec2f { float m_x; float m_y; };
extern "C" {
extern const float lbl_101_rodata_8;
extern const float lbl_101_rodata_18;
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
}

extern "C" void fn_101_FE70(void* object) {
    unsigned char* self = reinterpret_cast<unsigned char*>(object);
    Vec2f zero;
    Vec2f local8;
    zero.m_x = lbl_101_rodata_8;
    zero.m_y = lbl_101_rodata_8;
    Vec2f* p = fn_101_FE5C(reinterpret_cast<Vec2f*>(self + 0x20), &zero);
    p = fn_101_FE5C(reinterpret_cast<Vec2f*>(self + 0x10), p);
    fn_101_FE5C(reinterpret_cast<Vec2f*>(self + 0x8), p);
    local8.m_x = lbl_101_rodata_18;
    local8.m_y = lbl_101_rodata_18;
    p = fn_101_FE5C(reinterpret_cast<Vec2f*>(self + 0x28), &local8);
    fn_101_FE5C(reinterpret_cast<Vec2f*>(self + 0x18), p);
    self[0x31] = 0;
    self[0x30] = 0;
    self[0x32] = 1;
}
