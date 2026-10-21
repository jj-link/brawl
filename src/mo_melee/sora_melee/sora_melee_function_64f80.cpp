#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}
    virtual void f5() {}
    virtual void f6() {}
    virtual void f7() {}
    virtual void f8() {}
    virtual u32 f11(int);
    virtual u32 f12(int);
};

struct B {
    u8 pad[0x54];
    VObj* c;
};

struct A {
    u8 pad[0xd8];
    B* b;
};

struct Outer {
    u8 pad[0x10];
    A* a;
    u8 pad2[0x61 - 0x14];
    u8 flag;
};

extern "C" bool fn_27_64F80(Outer* p) {
    if (p->flag == 1) {
        if (p->a->b->c->f12(0) == 1) {
            return true;
        }
        if (p->a->b->c->f11(0) == 1) {
            return true;
        }
    }
    return false;
}
