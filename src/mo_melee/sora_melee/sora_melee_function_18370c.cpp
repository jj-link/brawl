#include <types.h>
#pragma force_active on

class Vt {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

struct Mid {
    u8 pad[0x40];
    Vt* m_40;
};

struct Outer {
    u8 pad[0xd8];
    Mid* m_d8;
};

extern "C" void fn_27_18370C(void* unused, Outer* p) {
    p->m_d8->m_40->v12();
}
