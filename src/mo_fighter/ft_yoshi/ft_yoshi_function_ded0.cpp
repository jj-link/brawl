#pragma force_active on
struct Vec2f_95 {
    float m_x;
    float m_y;
};

extern "C" const float lbl_95_rodata_C;

extern "C" void fn_95_DF08(Vec2f_95* dst, const Vec2f_95* src);

extern "C" void fn_95_DED0(char* self) {
    Vec2f_95 zero;
    zero.m_x = lbl_95_rodata_C;
    zero.m_y = lbl_95_rodata_C;
    fn_95_DF08((Vec2f_95*)(self + 8), &zero);
}
