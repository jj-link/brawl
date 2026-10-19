#include <types.h>
#pragma force_active on

class soFooBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" bool fn_27_A1C84(soFooBase* p) {
    return !p->vfunc3();
}
