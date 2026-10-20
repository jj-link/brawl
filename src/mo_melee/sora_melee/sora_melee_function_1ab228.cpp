#include <types.h>
#pragma force_active on

struct Base1 {
    virtual ~Base1();
    s32 unk4;
    s32 unk8;
};

struct Base2 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual s32 f4();
    virtual void f5();
    virtual s32 f6();
};

struct Derived : public Base1, public Base2 {
};

extern "C" {
s32 fn_27_1AB228(Derived* p) {
    return p->f4();
}
}
