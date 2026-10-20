#include <types.h>
#pragma force_active on

class fnBaseA {
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
    u32 pad0;
    u32 pad1;
    u32 pad2;
};

class fnBaseB {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
};

class fnDerived : public fnBaseA, public fnBaseB {
public:
    virtual void g13();
};

extern "C" void fn_27_1AD52C(fnDerived& p) {
    fnBaseB& b = p;
    b.g13();
}
