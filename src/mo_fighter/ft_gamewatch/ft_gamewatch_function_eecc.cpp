#pragma force_active on
struct Vec2f {
    float m_x;
    float m_y;
};

extern "C" const float lbl_107_rodata_C;
extern "C" void fn_107_EF04(Vec2f* dst, const Vec2f* src);

extern "C" void fn_107_EECC(Vec2f* object) {
    Vec2f value;
    value.m_x = lbl_107_rodata_C;
    value.m_y = lbl_107_rodata_C;
    fn_107_EF04(object + 1, &value);
}
