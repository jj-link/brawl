#include <types.h>
#pragma force_active on

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3();
};

struct Owner {
    u8 pad[0x10];
    Obj* a;
    Obj* b;
    Obj* c;
};

extern "C" s32 fn_100_9A24(Owner* arg0) {
    s32 max = arg0->c->f3();
    if (max < arg0->a->f3()) {
        max = arg0->a->f3();
    }
    if (max < arg0->b->f3()) {
        max = arg0->b->f3();
    }
    return max;
}
