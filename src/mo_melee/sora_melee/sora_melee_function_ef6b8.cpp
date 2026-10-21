#include <types.h>
#pragma force_active on

extern "C" void fn_27_FDFB0(s16* a, void* b);

class Inner {
public:
    virtual void v0();
    virtual void* getItem(s32 index);
    virtual void v2();
    virtual s32 getCount();
};

class Sink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void apply(void** p);
};

class Outer {
public:
    virtual void v0();
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" {
void fn_27_EF6B8(Outer* self, s16* mask, Sink* sink) {
    s16 sp8;
    void* spC;
    s32 n = self->m_inner.getCount();
    for (s32 i = 0; i < n; i++) {
        fn_27_FDFB0(&sp8, self->m_inner.getItem(i));
        if (sp8 & *mask) {
            spC = self->m_inner.getItem(i);
            sink->apply(&spC);
        }
    }
}
}
