#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual void action(s32 idx);
};

struct Outer {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 getCount();
    u8 pad[0x10 - 4];
    Inner inner;
};

extern "C" s32 fn_41_345F4(Outer* self, s32 idx);

extern "C" void fn_41_342A8(Outer* self, s32 idx) {
    if (idx <= -1) {
        self->inner.action(0);
        return;
    }
    s32 result = fn_41_345F4(self, idx);
    if (result < 0) {
        self->inner.action(0);
    } else {
        self->inner.action(result);
    }
}
