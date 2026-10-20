#include <types.h>
#pragma force_active on

struct C {
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
};

extern "C" void fn_27_263720(void* self) {
    void* a = *reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x180);
    void* b = *reinterpret_cast<void**>(reinterpret_cast<u8*>(a) + 0x1C);
    reinterpret_cast<C*>(b)->aa();
}
