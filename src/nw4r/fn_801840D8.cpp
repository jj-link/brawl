#include <types.h>
#pragma force_active on

class InnerBase {
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
    virtual u32 v15(u32 a, u32 b);
};

class Outer {
public:
    u8 pad[0x10];
    InnerBase* inner;
};

extern "C" void fn_801840D8(Outer* self, u32 a) {
    if (self->inner == 0)
        return;
    self->inner->v15(a, 1);
}
