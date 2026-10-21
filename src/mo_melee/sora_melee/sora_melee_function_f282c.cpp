#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE050(s16* a, s16* b);

class Inner {
public:
    virtual void v0();
    virtual s32 get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Sink {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void apply(s32* p);
};

class Outer {
public:
    char pad[0x10];
    Inner inner;
};

extern "C" {
void fn_27_F282C(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_FE050(&tmp, (s16*)self->inner.get(i));
        if (tmp & *mask) {
            s32 v = self->inner.get(i);
            sink->apply(&v);
        }
    }
}
}
