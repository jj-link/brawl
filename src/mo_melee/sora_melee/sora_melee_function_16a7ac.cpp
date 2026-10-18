#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int a, int b);
    virtual void v4();
    virtual void v5();
};

struct Outer {
    u32 unk0;
    Inner* m_inner;
};

extern "C" {
void fn_27_16A7AC(Outer* self, int a, int b, int c) {
    self->m_inner->v3(a, c);
}
}
