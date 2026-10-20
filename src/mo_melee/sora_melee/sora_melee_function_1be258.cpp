#include <types.h>
#pragma force_active on

class fn27Sub {
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
};

struct fn27Outer {
    u8 pad[0x10];
    fn27Sub sub;
};

extern "C" {
void fn_27_1BE258(fn27Outer* p) {
    fn27Sub* s = &p->sub;
    s->f8();
}
}
