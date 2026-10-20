#include <types.h>
#pragma force_active on
extern "C" {

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual short* action(s32 idx);
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

s32 fn_41_345F4(Outer* self, s32 idx);
void fn_41_346F4(short* a, short* b);

void fn_41_34498(short* out, Outer* self, s32 idx) {
    s32 result = fn_41_345F4(self, idx);
    if (result < 0) {
        *out = 0;
    } else {
        short* p = self->inner.action(result);
        fn_41_346F4(out, p);
    }
}
}
