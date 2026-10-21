#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 idx);
    virtual void vf2();
    virtual s32 count();
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
    virtual void vf10(void** p);
};

class Outer {
public:
    virtual void vf0();
    char pad[0xC];
    Inner mem;
};

extern "C" {
void fn_27_1CF51C(s16* dest, s16* src);

void fn_27_1C15E0(Outer* self, s16* mask, Visitor* visitor) {
    s32 count = self->mem.count();
    for (s32 i = 0; i < count; i++) {
        s16 val;
        fn_27_1CF51C(&val, (s16*)self->mem.vf1(i));
        if (val & *mask) {
            void* p = self->mem.vf1(i);
            visitor->vf10(&p);
        }
    }
}
}
