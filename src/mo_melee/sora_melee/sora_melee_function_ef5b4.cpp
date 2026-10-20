#include <types.h>
#pragma force_active on

struct Inner {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};

struct Outer {
    u32 pad[4];
    Inner m_in;
};

extern "C" void fn_27_EF5B4(Outer* o) {
    Inner* p = &o->m_in;
    p->b();
}
