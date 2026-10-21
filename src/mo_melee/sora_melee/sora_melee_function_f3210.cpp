#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Sink {
public:
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void apply(void** p) = 0;
};

class Outer {
public:
    u8 pad[0x10];
    Inner inner;
};

extern "C" void fn_27_FE050(s16* a, void* b);

extern "C" {
void fn_27_F3210(Outer* self, s16* mask, Sink* sink) {
    s16 sp8;
    void* spC;
    s32 count = self->inner.count();
    for (s32 i = 0; i < count; i++) {
        fn_27_FE050(&sp8, self->inner.get(i));
        if (sp8 & *mask) {
            spC = self->inner.get(i);
            sink->apply(&spC);
        }
    }
}
}
