#include <types.h>
#pragma force_active on

extern "C" void fn_27_1CF4F4(s16* a, const s16* b);

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
    virtual void vf10(void** p);
};

class soOuter {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    soInner m_inner;
};

extern "C" {
void fn_27_293D04(soOuter* self, s16* mask, soVisitor* visitor) {
    s32 n = self->m_inner.vf3();
    for (s32 i = 0; i < n; i++) {
        s16 flags;
        fn_27_1CF4F4(&flags, (const s16*)self->m_inner.vf1(i));
        if (flags & *mask) {
            void* p = self->m_inner.vf1(i);
            visitor->vf10(&p);
        }
    }
}
}
