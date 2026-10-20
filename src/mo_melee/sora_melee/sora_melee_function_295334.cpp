#include <types.h>
#pragma force_active on

class Ret {
public:
    virtual void dummy();
    s32 m_val;
};

class Inner {
public:
    virtual void f0();
    virtual Ret* f1();
};

class Outer {
public:
    char m_pad[0x10];
    Inner m_inner;
};

extern "C" {
s32 fn_27_295334(Outer* self) {
    Inner* p = &self->m_inner;
    return p->f1()->m_val;
}
}
