#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE0C8(void* r3, void* r4);

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 idx);
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

extern "C" {
void fn_27_1E626C(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 flags;
        fn_27_FE0C8(&flags, self->m_inner.get(i));
        if (flags & *mask) {
            void* p = self->m_inner.get(i);
            sink->apply(&p);
        }
    }
}
}
