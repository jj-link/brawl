#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual u32 get(u32 index);
    virtual void v2();
    virtual s32 count();
};

struct Outer {
    u32 pad[4];
    Inner inner;
};

struct Visitor {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void visit(u32* value);
};

extern "C" void fn_27_1CE738(Outer* self, Visitor* visitor) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        u32 val = self->inner.get(i);
        visitor->visit(&val);
    }
}
