#include <types.h>
#pragma force_active on

struct soIface {
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
    virtual void v13(u32 arg);
};

extern "C" {
void fn_27_29BF90(u32 unused, u8* p4, s32 p5) {
    if (p5 == 0) {
        u8* x = *(u8**)(p4 + 0x60);
        u8* y = *(u8**)(x + 0xd8);
        soIface* z = *(soIface**)(y + 0x64);
        z->v13(0x11000000);
    }
}
}
