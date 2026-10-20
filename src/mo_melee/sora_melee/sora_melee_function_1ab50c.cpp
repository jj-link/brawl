#include <types.h>
#pragma force_active on

struct Sub {
    virtual s32 v0();
    virtual s32 v1();
    virtual s32 v2();
    virtual s32 v3();
    virtual s32 v4();
    virtual s32 v5();
    virtual s32 v6();
};

struct Outer {
    u32 pad[3];
    Sub sub;
};

extern "C" {
s32 fn_27_1AB50C(Outer* self) {
    Sub* p = &self->sub;
    return p->v4();
}
}
