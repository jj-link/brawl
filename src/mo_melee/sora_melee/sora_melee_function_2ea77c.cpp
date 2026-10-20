#include <types.h>
#pragma force_active on

class fn27Sub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

class fn27Outer {
public:
    u32 pad[4];
    fn27Sub sub;
};

extern "C" void fn_27_2EA77C(fn27Outer* p) {
    p->sub.vf8();
}
