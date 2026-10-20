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
};

class fn27Outer {
public:
    u32 pad[3];
    fn27Sub sub;
};

extern "C" void fn_27_1A9AA4(fn27Outer* p) {
    p->sub.f4();
}
