#include <types.h>
#pragma force_active on

class soVirtualBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(s32 value);
};

extern "C" {
void fn_27_B6CC4(soVirtualBase* self) {
    self->vfunc4(1);
}
}
