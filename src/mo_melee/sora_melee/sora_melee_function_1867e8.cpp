#include <types.h>
#pragma force_active on

class Iface {
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
    virtual void target();
};

extern "C" {
void fn_27_1867E8(void* p1, u8* p2) {
    Iface* sub = *(Iface**)(*(u8**)(p2 + 0xd8) + 0x40);
    sub->target();
}
}
