#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE168(s16* dst, s16* src);

class soInner {
public:
    virtual void vf0();
    virtual void* vf1(s32 idx);
    virtual void vf2();
    virtual s32 vf3();
};

class soVisitor {
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

class soOuter {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    soInner m_inner;
};

extern "C" {
void fn_27_2950EC(soOuter* self, s16* mask, soVisitor* visitor) {
    s16 sp8;
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        fn_27_FE168(&sp8, (s16*)self->m_inner.vf1(i));
        if (sp8 & *mask) {
            void* p = self->m_inner.vf1(i);
            visitor->apply(&p);
        }
    }
}
}
