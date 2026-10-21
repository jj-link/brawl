#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE168(s16* dst, s16* src);

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
    virtual void visit(void** p);
};

class Outer {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" {
void fn_27_1C0BFC(Outer* self, s16* mask, Visitor* v) {
    s16 sp8;
    void* spC;
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        fn_27_FE168(&sp8, (s16*)self->m_inner.get(i));
        if (sp8 & *mask) {
            spC = self->m_inner.get(i);
            v->visit(&spC);
        }
    }
}
}
