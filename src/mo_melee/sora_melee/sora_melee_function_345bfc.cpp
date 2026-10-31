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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual u32 target(u32 x);
};

struct fn27Mid {
    u8 pad[0x64];
    fn27Inner* inner;
};

struct fn27Outer {
    u8 pad[0xd8];
    fn27Mid* mid;
};

extern "C" u32 fn_27_345BFC(u32 a, s32 b, u32 c, fn27Outer* o) {
    if (b == 2) {
        return a;
    }
    return o->mid->inner->target(0x1200003D);
}
