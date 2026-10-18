#include <types.h>
#pragma force_active on

class IA {
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
    virtual bool f17(u32 id) = 0;
};

class IB {
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
    virtual void f15(s32 a, void* p) = 0;
};

class IC {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3(s32 id, void* obj) = 0;
};

struct Mid {
    u8 pad0[0x54];
    IB* b;
    u8 pad1[0xc];
    IA* a;
    u8 pad2[0x8];
    IC* c;
};

struct Obj {
    u8 pad[0xd8];
    Mid* mid;
};

struct LocalData {
    s32 a;
    u8 b;
};

extern "C" void fn_27_18423C(void*, Obj* obj) {
    if (obj->mid->a->f17(0x22000012)) {
        LocalData d;
        d.a = 0x14;
        d.b = 0;
        obj->mid->b->f15(0, &d);
        obj->mid->c->f3(0xd1, obj);
    }
}
