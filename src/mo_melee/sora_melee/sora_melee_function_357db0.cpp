#include <types.h>
#pragma force_active on

class Iface1 {
public:
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
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f20(u32 a) = 0;
};

class Iface2 {
public:
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
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f18(u32 a, u32 b) = 0;
};

struct Sub {
    u8 pad0[0x64];
    Iface1* a;
    u8 pad1[0x84 - 0x68];
    Iface2* b;
};

struct Outer {
    u8 pad[0xd8];
    Sub* sub;
};

extern "C" {
void fn_27_357DB0(void* unused, Outer* obj) {
    obj->sub->a->f20(0x12000041);
    obj->sub->b->f18(0, 0);
}
}
