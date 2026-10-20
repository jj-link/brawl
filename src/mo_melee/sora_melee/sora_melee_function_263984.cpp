#include <types.h>
#pragma force_active on

class fn27Inner {
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
    virtual void* v10();
};

class fn27Mid {
public:
    u8 pad[0xc];
    fn27Inner* inner;
};

class fn27Top {
public:
    u8 pad[0x180];
    fn27Mid* mid;
};

extern "C" {
void* fn_27_263984(fn27Top* self) {
    return self->mid->inner->v10();
}
}
