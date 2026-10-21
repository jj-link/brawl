#include <types.h>
#pragma force_active on

struct Visitor {
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

struct Source {
    virtual void s0();
    virtual void* get(s32 i);
    virtual void s2();
    virtual s32 count();
};

struct Outer {
    void* m_vptr;
    u32 m_pad[3];
    Source m_src;
};

extern "C" {
void fn_27_FAA64(Outer* self, Visitor* vis) {
    s32 n = self->m_src.count();
    for (s32 i = 0; i < n; i++) {
        void* p = self->m_src.get(i);
        vis->visit(&p);
    }
}
}
