#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE1E0(s16* r3, const void* r4);

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Visitor {
public:
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
    virtual void apply(void** p);
};

class Outer {
public:
    u8 pad[0x10];
    Inner inner;
};

extern "C" {
void fn_27_1E4E84(Outer* self, s16* mask, Visitor* visitor) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 flags;
        fn_27_FE1E0(&flags, self->inner.get(i));
        if (flags & *mask) {
            void* p = self->inner.get(i);
            visitor->apply(&p);
        }
    }
}
}
