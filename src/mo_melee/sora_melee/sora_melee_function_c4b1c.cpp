#include <types.h>
#pragma force_active on

struct Inner {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};

struct Outer {
    u32 pad[4];
    Inner m_inner;
};

extern "C" void fn_27_C4B1C(Outer* p) {
    p->m_inner.d();
}
