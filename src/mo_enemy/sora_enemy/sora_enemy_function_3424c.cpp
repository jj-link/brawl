#include <types.h>
#pragma force_active on

struct Inner {
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

extern "C" void fn_41_3424C(Outer* self, s32 idx) {
    s32 result = fn_41_345F4(self, idx);
    if (result >= 0) {
        self->inner.action(result);
    }
}
