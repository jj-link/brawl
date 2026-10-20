#include <types.h>
#pragma force_active on

class IFace27 {
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f22(u32 a, u32 b);
};

struct Mid27 {
    char pad[0x64];
    IFace27* p64;
};

struct Outer27 {
    char pad[0xd8];
    Mid27* pd8;
};

extern "C" {
void fn_27_151D24(void* unused, Outer27* self, u32 x) {
    self->pd8->p64->f22(x, 0x2200001b);
}
}
