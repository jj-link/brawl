#include <types.h>
#pragma force_active on

class fnA40Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

class fnA40Outer {
public:
    u8 pad[0x34];
    fnA40Inner* m_inner;
};

extern "C" {
void fn_27_A40F4(fnA40Outer* p) {
    p->m_inner->v8();
}
}
