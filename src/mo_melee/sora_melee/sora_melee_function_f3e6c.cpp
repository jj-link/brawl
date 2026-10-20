#include <types.h>
#pragma force_active on

class fnSub {
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
    virtual void v15();
};

class fnOuter {
public:
    u32 m_pad[4];
    fnSub m_sub;
};

extern "C" void fn_27_F3E6C(fnOuter* self) {
    self->m_sub.v13();
}
