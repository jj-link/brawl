#include <types.h>
#pragma force_active on

class fn27Vtbl {
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

struct fn27Inner {
    u8 pad[0x40];
    fn27Vtbl* obj;
};

struct fn27Outer {
    u8 pad[0xd8];
    fn27Inner* inner;
};

extern "C" {
void fn_27_1835B4(void* unused, fn27Outer* p) {
    p->inner->obj->v12();
}
}
