#include <types.h>
#pragma force_active on

struct Iface {
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
    virtual void v15(void* p);
};

struct Inner {
    u8 pad[0x10];
    void* f10;
};

struct Mid {
    u8 pad[0xa4];
    Inner* fa4;
};

struct Obj {
    u8 pad[0x64c];
    Mid* f64c;
    u8 pad2[0x654 - 0x650];
    Iface* f654;
};

extern "C" void fn_2_1732C(Obj* self) {
    self->f654->v15(self->f64c->fa4->f10);
}
