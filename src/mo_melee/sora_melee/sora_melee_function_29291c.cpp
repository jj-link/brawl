#include <types.h>
#pragma force_active on

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
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_FE1E0(void* r3, const void* r4);

extern "C" {
void fn_27_29291C(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 flags;
        void* p = self->m_inner.get(i);
        fn_27_FE1E0(&flags, p);
        if (flags & *mask) {
            void* q = self->m_inner.get(i);
            sink->apply(&q);
        }
    }
}
}
