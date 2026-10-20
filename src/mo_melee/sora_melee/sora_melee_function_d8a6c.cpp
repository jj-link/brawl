#include <types.h>
#pragma force_active on

struct fn_27_D8A6C_Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct fn_27_D8A6C_Outer {
    u32 pad[4];
    fn_27_D8A6C_Sub sub;
};

extern "C" void fn_27_D8A6C(fn_27_D8A6C_Outer* p) {
    fn_27_D8A6C_Sub* s = &p->sub;
    s->f1();
}
