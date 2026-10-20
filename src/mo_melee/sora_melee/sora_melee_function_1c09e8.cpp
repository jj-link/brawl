#include <types.h>
#pragma force_active on

class fn27Inner {
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

struct fn27Outer {
    u8 pad[0x10];
    fn27Inner inner;
};

extern "C" {
void fn_27_1C09E8(fn27Outer* p) {
    p->inner.vf8();
}
}
