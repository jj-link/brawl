#pragma force_active on
typedef unsigned char u8;

struct Vec2f_95 {
    float m_x;
    float m_y;
};

extern "C" const float lbl_95_rodata_C;
extern "C" const float lbl_95_rodata_10;
extern "C" Vec2f_95* fn_95_DF08(Vec2f_95* dst, const Vec2f_95* src);

extern "C" void fn_95_DF1C(char* self) {
    Vec2f_95 a;
    Vec2f_95 b;
    a.m_x = lbl_95_rodata_C;
    a.m_y = lbl_95_rodata_C;
    fn_95_DF08((Vec2f_95*)(self + 0x8), fn_95_DF08((Vec2f_95*)(self + 0x10), fn_95_DF08((Vec2f_95*)(self + 0x20), &a)));
    b.m_x = lbl_95_rodata_10;
    b.m_y = lbl_95_rodata_10;
    fn_95_DF08((Vec2f_95*)(self + 0x18), fn_95_DF08((Vec2f_95*)(self + 0x28), &b));
    *(u8*)(self + 0x31) = 0;
    *(u8*)(self + 0x30) = 0;
    *(u8*)(self + 0x32) = 1;
}
