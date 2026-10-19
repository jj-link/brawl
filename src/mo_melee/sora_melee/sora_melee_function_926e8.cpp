#include <types.h>
#pragma force_active on

struct Result {
    s32 field0;
    s32 field4;
};

struct Inner {
    virtual void v0();
    virtual Result* v1();
};

struct Outer {
    s32 pad0;
    s32 pad4;
    Inner* p8;
};

extern "C" s32 fn_27_926E8(Outer* self) {
    return self->p8->v1()->field4;
}
