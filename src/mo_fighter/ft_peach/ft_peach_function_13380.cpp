#include <types.h>
#pragma force_active on

struct Base16 {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
};

struct Foo : Base16 {
    virtual void f14() = 0;
};

extern "C" void fn_103_13380(Foo* obj) {
    obj->f14();
}
