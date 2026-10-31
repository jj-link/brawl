#include <types.h>
#pragma force_active on

struct soC {
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
    virtual u32 v10(u32 a, u32 b);
};

struct soB {
    u8 pad[0x40];
    soC* c;
};

struct soA {
    u8 pad[0xd8];
    soB* b;
};

extern "C" {
u32 fn_27_192688(u32 p1, soA* p2, s32 p3) {
    if (p3 == 0x105) {
        return p1;
    }
    if (p3 == 0x106) {
        return p1;
    }
    return p2->b->c->v10(0, 0);
}
}
