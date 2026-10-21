#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Visitor {
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
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" {
void fn_27_FE0A0(s16* a, const s16* b);

void fn_27_F4FBC(Outer* self, s16* mask, Visitor* visitor) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 tmp;
        fn_27_FE0A0(&tmp, (const s16*)self->m_inner.get(i));
        if (tmp & *mask) {
            void* p = self->m_inner.get(i);
            visitor->apply(&p);
        }
    }
}
}
