#pragma force_active on
#include <types.h>

struct Inner {
    u8 pad[0x10];
    void* f10;
};

struct Iface {
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
    virtual void call(void* p);
};

struct Obj {
    u8 pad[0x40];
    Inner* f40;
    Iface* f44;
};

extern "C" void fn_800BF830(Obj* self) {
    self->f44->call(self->f40->f10);
}
