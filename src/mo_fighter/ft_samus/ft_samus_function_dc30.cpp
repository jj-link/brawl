#pragma force_active on
struct Vec2fLocal {
    float m_x;
    float m_y;
};

extern "C" const float lbl_94_rodata_C;
extern "C" void fn_94_DC68(Vec2fLocal* dst, const Vec2fLocal* src);

extern "C" void fn_94_DC30(Vec2fLocal* object) {
    Vec2fLocal zero;
    zero.m_x = lbl_94_rodata_C;
    zero.m_y = lbl_94_rodata_C;
    fn_94_DC68(object + 1, &zero);
}
