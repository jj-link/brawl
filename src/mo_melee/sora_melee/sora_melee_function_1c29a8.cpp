#include <types.h>
#pragma force_active on

extern "C" void fn_27_1CF51C(s16* dest, s16* src);

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 idx);
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
    virtual void vf10(void* p);
};

class Outer {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" {
void fn_27_1C29A8(Outer* self, s16* mask, Sink* sink) {
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        s16 sp8;
        fn_27_1CF51C(&sp8, (s16*)self->m_inner.vf1(i));
        if (sp8 & *mask) {
            s32 v = (s32)self->m_inner.vf1(i);
            sink->vf10((void*)&v);
        }
    }
}
}
