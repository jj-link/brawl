#include <types.h>
#pragma force_active on

class fn27Base {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    s32 m_pad[(0x64 - 4) / 4];
    s32 m_64;
};

extern "C" void fn_27_23EA0(fn27Base* self);

void fn_27_23EA0(fn27Base* self) {
    self->v19();
    self->m_64 = -1;
}
