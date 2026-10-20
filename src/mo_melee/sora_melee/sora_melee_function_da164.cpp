#include <types.h>
#pragma force_active on

class fn_27_Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual void f21();
};

struct fn_27_Holder {
    u8 pad[8];
    fn_27_Obj* obj;
};

extern "C" {
void fn_27_DA164(fn_27_Holder* p) {
    p->obj->f19();
}
}
