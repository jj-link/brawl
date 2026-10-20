#include <types.h>
#pragma force_active on

class soSubBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

struct soOuterHolder {
    u32 unk0[4];
    soSubBase sub;
};

extern "C" {
void fn_27_1B1608(soOuterHolder* p) {
    soSubBase* s = &p->sub;
    s->vf3();
}
}
