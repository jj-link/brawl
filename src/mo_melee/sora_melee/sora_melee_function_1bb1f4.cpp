#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u8 pad[0x10];
    Inner m_10;
};

extern "C" {
void fn_27_1BB1F4(Outer* p) {
    Inner* in = &p->m_10;
    in->f1();
}
}
