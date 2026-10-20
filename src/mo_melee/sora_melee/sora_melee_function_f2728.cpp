#include <types.h>
#pragma force_active on

struct fn27Sub {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct fn27Outer {
    u8 pad[0x10];
    fn27Sub sub;
};

extern "C" void fn_27_F2728(fn27Outer* self) {
    fn27Sub* p = &self->sub;
    p->vf1();
}
