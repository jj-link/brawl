#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 index);
    virtual void vf2();
    virtual s32 count();
};

struct Outer {
    u8 pad[0x10];
    Inner inner;
};

class Visitor {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void apply(s32* p);
};

extern "C" void fn_27_714A4(s16*, void*);

extern "C" {
void fn_27_1ABEA8(Outer* self, s16* arg1, Visitor* arg2) {
    s32 count = self->inner.count();
    for (s32 i = 0; i < count; i++) {
        s16 sp8;
        fn_27_714A4(&sp8, self->inner.get(i));
        if (sp8 & *arg1) {
            s32 spC = (s32)self->inner.get(i);
            arg2->apply(&spC);
        }
    }
}
}
