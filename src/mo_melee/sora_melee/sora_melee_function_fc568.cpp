#include <types.h>
#pragma force_active on

struct soSubObject {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct soOuterObject {
    u8 pad[0x10];
    soSubObject sub;
};

extern "C" void fn_27_FC568(soOuterObject* p) {
    soSubObject* s = &p->sub;
    s->vf1();
}
