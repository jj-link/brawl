#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
};

class Outer {
public:
    u32 m_pad[3];
    Inner m_inner;
};

extern "C" int fn_27_1AB620(Outer* self) {
    Inner* p = &self->m_inner;
    return p->f4();
}
