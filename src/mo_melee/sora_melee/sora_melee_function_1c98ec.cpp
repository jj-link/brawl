#include <types.h>
#pragma force_active on

class soBase1 {
public:
    u32 m_0;
    u32 m_4;
    u32 m_8;
    u32 m_c;
};

class soBase2 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
};

class soOuter : public soBase1, public soBase2 {
};

extern "C" {
void fn_27_1C98EC(soOuter& p) {
    soBase2& b = p;
    b.f13();
}
}
