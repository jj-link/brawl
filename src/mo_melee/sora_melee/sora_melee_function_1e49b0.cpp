#include <types.h>
#pragma force_active on

class soVirtInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class soVirtOuter {
public:
    u32 unk0;
    u32 unk4;
    u32 unk8;
    soVirtInner m_inner;
};

extern "C" {
void fn_27_1E49B0(soVirtOuter* self) {
    soVirtInner* p = &self->m_inner;
    p->f4();
}
}
