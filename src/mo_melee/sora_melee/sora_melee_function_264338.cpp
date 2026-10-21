#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void s0();
    virtual void* get(s32 index);
    virtual void s2();
    virtual s32 count();
};

class Visitor {
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
    char pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_FE0A0(s16* a, const s16* b);

extern "C" {
void fn_27_264338(Outer* self, s16* flags, Visitor* visitor) {
    s32 count = self->m_inner.count();
    for (s32 i = 0; i < count; i++) {
        void* p = self->m_inner.get(i);
        s16 val;
        fn_27_FE0A0(&val, (const s16*)p);
        if (val & *flags) {
            void* p2 = self->m_inner.get(i);
            visitor->apply(&p2);
        }
    }
}
}
