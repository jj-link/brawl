#include <types.h>
#pragma force_active on

struct fn27Sub {
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
    virtual void target();
};

struct fn27Outer {
    u32 pad[4];
    fn27Sub sub;
};

extern "C" void fn_27_1C8524(fn27Outer* p) {
    fn27Sub* s = (fn27Sub*)((char*)p + 0x10);
    s->target();
}
