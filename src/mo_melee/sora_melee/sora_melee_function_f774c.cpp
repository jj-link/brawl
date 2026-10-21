#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 index);
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
    virtual void apply(void** p);
};

class Outer {
public:
    char pad[0x10];
    Inner m_inner;
};

extern "C" {
extern void fn_27_FE140(s16* dest, s16* src);

void fn_27_F774C(Outer* self, s16* flags, Visitor* visitor) {
    s16 sp8;
    void* spC;
    s32 count = self->m_inner.count();
    for (s32 i = 0; i < count; i++) {
        void* item = self->m_inner.get(i);
        fn_27_FE140(&sp8, (s16*)item);
        if (sp8 & *flags) {
            spC = self->m_inner.get(i);
            visitor->apply(&spC);
        }
    }
}
}
