#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f2();
    virtual u32* f3();
};

struct Outer {
    char pad[0x10];
    Inner m_inner;
};

extern "C" u32 fn_27_F8D5C(Outer* self) {
    return self->m_inner.f3()[1];
}
