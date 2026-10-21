#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE208(s16* dest, s16* src);

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 idx);
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
    virtual void visit(void** p);
};

class Outer {
public:
    virtual void v0();
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" {
void fn_27_FDA34(Outer* self, s16* mask, Visitor* visitor) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        s16 val;
        fn_27_FE208(&val, (s16*)self->m_inner.get(i));
        if (val & *mask) {
            void* p = self->m_inner.get(i);
            visitor->visit(&p);
        }
    }
}
}
