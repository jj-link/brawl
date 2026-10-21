#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 index);
    virtual void vf2();
    virtual s32 vf3();
};

class Visitor {
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

class Outer {
public:
    char pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_FE0A0(s16* a, const s16* b);

extern "C" {
void fn_27_F45D8(Outer* self, s16* flags, Visitor* visitor) {
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        void* p = self->m_inner.vf1(i);
        s16 val;
        fn_27_FE0A0(&val, (const s16*)p);
        if (val & *flags) {
            void* q = self->m_inner.vf1(i);
            visitor->vf10(&q);
        }
    }
}
}
