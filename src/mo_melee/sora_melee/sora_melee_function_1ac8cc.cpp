#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 index);
    virtual void vf2();
    virtual s32 vf3();
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
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" void fn_27_714A4(s16* out, void* src);

extern "C" void fn_27_1AC8CC(Outer* self, s16* arg1, Visitor* arg2) {
    s16 sp8;
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        void* p = self->m_inner.vf1(i);
        fn_27_714A4(&sp8, p);
        if (sp8 & *arg1) {
            void* p2 = self->m_inner.vf1(i);
            arg2->vf10(&p2);
        }
    }
}
