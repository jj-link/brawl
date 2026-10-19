#pragma force_active on
struct Vec2f {
    float m_x;
    float m_y;
};

extern "C" {
void fn_8003DC64(Vec2f*, float, Vec2f*);
}
extern float lbl_41_rodata_C9C;
extern float lbl_41_rodata_CE0;

extern "C" {
Vec2f fn_41_1E5B0(float a, float b, float s) {
    Vec2f src;
    Vec2f out;
    src.m_x = a * s;
    src.m_y = lbl_41_rodata_C9C;
    out.m_x = lbl_41_rodata_C9C;
    out.m_y = lbl_41_rodata_C9C;
    fn_8003DC64(&src, lbl_41_rodata_CE0 * (b * s), &out);
    return out;
}
}
