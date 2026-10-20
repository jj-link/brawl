#include <types.h>
#pragma force_active on

class soGeneralWorkAbstractStub {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
};

class soOuterStub {
public:
    u8 pad[0xc];
    soGeneralWorkAbstractStub m_inner;
};

extern "C" void fn_27_1AB3F8(soOuterStub* p) {
    p->m_inner.vfn4();
}
