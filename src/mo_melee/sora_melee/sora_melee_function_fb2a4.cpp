#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE1B8(s16* out, const s16* in);

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 i);
    virtual void v2();
    virtual s32 count();
};

class Outer {
public:
    virtual void v0();
    u8 m_pad[0xC];
    Inner m_inner;
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

extern "C" {
void fn_27_FB2A4(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_FE1B8(&tmp, (const s16*)self->m_inner.get(i));
        if (tmp & *mask) {
            void* p = self->m_inner.get(i);
            sink->apply(&p);
        }
    }
}
}
