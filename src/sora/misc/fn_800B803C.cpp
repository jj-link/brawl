#include <types.h>
#pragma force_active on

extern "C" {

struct Obj {
    virtual s32 v0();
    virtual s32 v1();
    virtual s32 v2();
    virtual s32 v3();
    virtual s32 v4();
    virtual s32 v5();
};

struct Holder {
    s32 pad0;
    Obj* target;
};

s32 fn_800B803C(Holder* h) {
    Obj* t = h->target;
    if (t)
        return t->v5();
    return (s32)t;
}

}
