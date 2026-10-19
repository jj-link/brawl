#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual bool vfn3();
};

extern "C" {
bool fn_27_106AE4(fn27Obj* p) {
    return !p->vfn3();
}
}
