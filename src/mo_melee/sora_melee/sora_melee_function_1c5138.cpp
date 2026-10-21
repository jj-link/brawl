#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32);
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
    virtual void vf10(void**);
};

class Outer {
public:
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_FE208(short* dest, short* src);

extern "C" {
void fn_27_1C5138(Outer* self, s16* flags, Visitor* visitor) {
    s16 sp8;
    void* spC;
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        void* p = self->m_inner.vf1(i);
        fn_27_FE208(&sp8, (s16*)p);
        if (sp8 & *flags) {
            void* p2 = self->m_inner.vf1(i);
            visitor->vf10(&p2);
        }
    }
}
}
