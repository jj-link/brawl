#include <types.h>
#pragma force_active on

struct fn27Base {
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

struct fn27Outer {
    u32 pad[4];
    fn27Base base;
};

extern "C" void fn_27_1C715C(fn27Outer* p) {
    return p->base.v13();
}
