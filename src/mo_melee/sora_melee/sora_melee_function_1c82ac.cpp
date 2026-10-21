#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE168(s16* dst, s16* src);

class Inner {
public:
    virtual void vf0();
    virtual void* vf1(s32 index);
    virtual void vf2();
    virtual s32 vf3();
};

class Outer {
public:
    char pad[0x10];
    Inner m_inner;
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
    virtual void apply(void** p);
};

extern "C" {
void fn_27_1C82AC(Outer* self, s16* flags, Sink* sink) {
    s32 n = self->m_inner.vf3();
    for (s32 i = 0; i < n; i++) {
        void* item = self->m_inner.vf1(i);
        s16 val;
        fn_27_FE168(&val, (s16*)item);
        if (val & *flags) {
            void* p = self->m_inner.vf1(i);
            sink->apply(&p);
        }
    }
}
}
