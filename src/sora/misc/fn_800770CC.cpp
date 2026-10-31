#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
extern const float lbl_805A1AC8;
extern const float lbl_805A1ACC;
}

class Sub {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void fn6();
    virtual void fn7();
    virtual void fn8();
    virtual void fn9();
    virtual void fn10();
    virtual void fn11();
    virtual void fn12(int, float);
};

struct Elem {
    Sub* m_sub;
    char pad[0x1C];
};

struct MainObj {
    char pad[0x2D4];
    Elem m_elems[32];
    char pad2[0x38];
    float m_val;
    char pad3[8];
    float m_mult;
};

extern "C" void fn_800770CC(MainObj* self, int count, float value) {
    float delta = lbl_805A1AC8 - value;
    float clamped = nw4r::math::FSelect(delta, value, lbl_805A1AC8);
    float lower = lbl_805A1ACC;
    self->m_val = nw4r::math::FSelect(lower - clamped, lower, clamped);
    if (count != 0) {
        float result = self->m_mult * self->m_val;
        for (unsigned int i = 0; i < 32; i++) {
            Sub* sub = self->m_elems[i].m_sub;
            if (sub != 0) {
                sub->fn12(0, result);
            }
        }
    }
}
