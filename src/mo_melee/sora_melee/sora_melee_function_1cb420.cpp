#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void* vf3(s32 idx);
    virtual void vf4();
    virtual s32 vf5();
};

class soSink {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void apply(void** p);
};

class soOuter {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    soInner m_inner;
};

extern "C" void fn_27_FE000(s16* dest, s16* src);

extern "C" {
void fn_27_1CB420(soOuter* self, s16* mask, soSink* sink) {
    s32 count = self->m_inner.vf5();
    for (s32 i = 0; i < count; i++) {
        s16 flags;
        fn_27_FE000(&flags, (s16*)self->m_inner.vf3(i));
        if (flags & *mask) {
            void* p = self->m_inner.vf3(i);
            sink->apply(&p);
        }
    }
}
}
