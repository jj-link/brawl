#include <types.h>
#pragma force_active on

struct soVirtualIface {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
};

struct soOwner {
    u8 pad[0x14c];
    soVirtualIface* m_iface;
};

extern "C" void fn_27_150FFC(soOwner* self) {
    self->m_iface->f18();
}
