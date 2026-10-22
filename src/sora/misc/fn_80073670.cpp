#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;
struct M { float m[12]; };
extern const float lbl_805A1AC8;
extern const float lbl_805A1ACC;
extern const float lbl_805A1AD8;
extern const float lbl_805A1ADC;
extern const float lbl_805A1AE0;
extern "C" float fn_801622C4(float);
extern "C" float fn_8016232C(float);
extern "C" void fn_801EC9D8(M*, VEC3*, VEC3*, VEC3*);

struct O {
    char p0[0x294];
    M mtx;
    float a, b, c;
    char p1[0x6e8 - 0x2d0];
    int i6e8;
    char p2[0x720 - 0x6ec];
    char c720, c721;
    char p3[2];
    int i724;
    char p4[0xb9c - 0x728];
    int w[5];
    int n[7];
};

extern "C" void fn_80073670(O* o) {
    o->c720 = 0;
    o->c721 = 0;
    o->i724 = 0;
    o->a = lbl_805A1AD8;
    o->b = lbl_805A1ADC;
    o->c = lbl_805A1AE0;
    VEC3 pos(lbl_805A1ACC, lbl_805A1ACC, lbl_805A1ACC);
    VEC3 up(lbl_805A1ACC, lbl_805A1AC8, lbl_805A1ACC);
    float s = -fn_8016232C(lbl_805A1ACC);
    VEC3 d(fn_801622C4(lbl_805A1ACC), lbl_805A1ACC, s);
    VEC3 t = pos + d;
    M m;
    fn_801EC9D8(&m, &pos, &up, &t);
    o->mtx = m;
    o->i6e8 = 0;
    for (int i = 0; i < 5; i++) o->w[i] = 0;
    for (int i = 0; i < 7; i++) o->n[i] = -1;
}
