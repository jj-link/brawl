#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void s0();
    virtual void* get(s32 index);
    virtual void s2();
    virtual s32 count();
};

class Outer {
public:
    char pad[0x10];
    Inner m_inner;
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

extern "C" void fn_27_FE118(s16* a, const s16* b);

extern "C" {
void fn_27_1CC7E8(Outer* self, s16* flag, Sink* sink) {
    s32 n = self->m_inner.count();
    s16 sp8;
    for (s32 i = 0; i < n; i++) {
        fn_27_FE118(&sp8, (const s16*)self->m_inner.get(i));
        if (sp8 & *flag) {
            void* p2 = self->m_inner.get(i);
            sink->apply(&p2);
        }
    }
}
}
