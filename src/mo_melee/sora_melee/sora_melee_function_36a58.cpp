#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void* f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 pad[2];
    Inner* m_inner;
};

extern "C" void* fn_27_36A58(Outer* p) {
    return (char*)p->m_inner->f1() + 0x28;
}
