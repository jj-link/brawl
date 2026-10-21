#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual s32 get(s32 index);
    virtual void v2();
    virtual s32 count();
};

struct Outer {
    u32 pad[4];
    Inner inner;
};

struct Visitor {
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
    virtual void visit(s32* value);
};

extern "C" void fn_27_1BC864(Outer* self, Visitor* visitor) {
    s32 count = self->inner.count();
    for (s32 i = 0; i < count; ++i) {
        s32 value = self->inner.get(i);
        visitor->visit(&value);
    }
}
