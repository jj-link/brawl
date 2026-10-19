#include <types.h>
#pragma force_active on

class soGeneralWorkAbstractStub {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" {
bool fn_27_39524(soGeneralWorkAbstractStub* self) {
    return !self->vfunc3();
}
}
