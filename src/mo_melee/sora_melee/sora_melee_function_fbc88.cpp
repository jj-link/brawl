#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* getItem(s32 index);
    virtual void vf2();
    virtual s32 getCount();
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

class Self {
public:
    char pad[0x10];
    Inner inner;
};

extern "C" void fn_27_FE1E0(void* r3, const void* r4);

extern "C" {
void fn_27_FBC88(Self* self, s16* arg1, Visitor* arg2) {
    s32 count = self->inner.getCount();
    s16 sp8;
    s32 spC;
    for (s32 i = 0; i < count; i++) {
        void* p = self->inner.getItem(i);
        fn_27_FE1E0(&sp8, p);
        if (sp8 & *arg1) {
            spC = (s32)self->inner.getItem(i);
            arg2->apply(&spC);
        }
    }
}
}
