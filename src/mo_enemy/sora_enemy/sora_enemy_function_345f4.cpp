#include <types.h>
#pragma force_active on

struct Elem {
    u8 pad[8];
    s32 val;
};

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual Elem* get(s32 idx);
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

extern "C" s32 fn_41_345F4(Outer* self, s32 idx) {
    if (idx <= -1) {
        return -1;
    }
    s32 count = self->getCount();
    for (s32 i = 0; i < count; i++) {
        Elem* e = self->inner.get(i);
        if (idx == e->val) {
            return i;
        }
    }
    return -1;
}
