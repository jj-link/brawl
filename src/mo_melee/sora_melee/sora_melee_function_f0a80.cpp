#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Outer {
public:
    char pad[0x10];
    Inner inner;
};

class Sink {
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
    virtual void apply(s32* val);
};

extern "C" void fn_27_FE000(s16* dest, s16* src);

extern "C" {
void fn_27_F0A80(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        void* p = self->inner.get(i);
        s16 sp8;
        fn_27_FE000(&sp8, (s16*)p);
        if (sp8 & *mask) {
            s32 spC = (s32)self->inner.get(i);
            sink->apply(&spC);
        }
    }
}
}
