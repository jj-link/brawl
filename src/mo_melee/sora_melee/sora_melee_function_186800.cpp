#include <types.h>
#pragma force_active on

class fn27_186800Inner {
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
    virtual void v19(s32 p);
};

struct fn27_186800Mid {
    u8 pad[0x40];
    fn27_186800Inner* inner;
};

struct fn27_186800Outer {
    u8 pad[0xd8];
    fn27_186800Mid* mid;
};

extern "C" {
void fn_27_186800(u32 p1, fn27_186800Outer* p2, s32 p3) {
    if (p3 == 0xd8) {
        return;
    }
    p2->mid->inner->v19(0);
}
}
