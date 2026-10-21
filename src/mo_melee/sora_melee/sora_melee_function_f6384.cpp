#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE0F0(s16* a, const s16* b);

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Sink {
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

class Outer {
public:
    virtual void o0();
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" {
void fn_27_F6384(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_FE0F0(&tmp, (const s16*)self->m_inner.get(i));
        if (tmp & *mask) {
            void* p = self->m_inner.get(i);
            sink->apply(&p);
        }
    }
}
}
