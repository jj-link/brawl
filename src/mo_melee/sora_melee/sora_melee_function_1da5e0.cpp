#include <types.h>
#pragma force_active on

class Base8 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s32 f7();
    virtual void f8();
    virtual void f9();
};

struct Holder {
    u8 pad[8];
    Base8 obj;
};

struct Lv3 {
    u8 pad[0x80];
    Holder* c;
};

struct Lv2 {
    u8 pad[0xd8];
    Lv3* b;
};

struct Lv1 {
    u8 pad[0x60];
    Lv2* a;
};

extern "C" {
s32 fn_27_1DA5E0(Lv1* p) {
    return p->a->b->c->obj.f7();
}
}
