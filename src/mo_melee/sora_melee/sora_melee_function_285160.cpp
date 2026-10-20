#include <types.h>
#pragma force_active on

class fn27InnerBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf8(u32 a, u32 b);
};

class fn27Outer {
public:
    u8 pad[0xf04];
    fn27InnerBase inner;
};

extern "C" {
void fn_27_285160(fn27Outer* self, u32 a) {
    self->inner.vf8(a, 0);
}
}
