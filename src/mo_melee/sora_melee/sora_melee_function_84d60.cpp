#include <types.h>
#pragma force_active on

struct Foo {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4();
};

extern "C" s32 fn_27_84D60(Foo* f) {
    return !f->v4();
}
