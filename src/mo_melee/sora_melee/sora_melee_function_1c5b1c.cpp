#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 index);
    virtual void vf2();
    virtual s32 count();
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
    virtual void apply(void** p);
};

class Owner {
public:
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" {
void fn_27_FE140(short* dest, short* src);

void fn_27_1C5B1C(Owner* self, s16* flags, Sink* sink) {
    s32 count = self->m_inner.count();
    for (s32 i = 0; i < count; i++) {
        s16 sp8;
        void* p = self->m_inner.get(i);
        fn_27_FE140(&sp8, (s16*)p);
        if (sp8 & *flags) {
            void* q = self->m_inner.get(i);
            sink->apply(&q);
        }
    }
}
}
