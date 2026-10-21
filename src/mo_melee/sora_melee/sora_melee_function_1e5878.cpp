#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 index);
    virtual void vf2();
    virtual s32 vf3();
};

class Sink {
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
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_FE050(s16*, s16*);

extern "C" {
void fn_27_1E5878(Outer* self, s16* flags, Sink* sink) {
    s32 n = self->m_inner.vf3();
    for (s32 i = 0; i < n; i++) {
        s16 sp8;
        void* p = self->m_inner.vf1(i);
        fn_27_FE050(&sp8, (s16*)p);
        if (sp8 & *flags) {
            void* p2 = self->m_inner.vf1(i);
            sink->vf10(&p2);
        }
    }
}
}
