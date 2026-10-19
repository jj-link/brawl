#include <types.h>
#pragma force_active on

class soSomeObj {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
    virtual void vfunc4();
};

extern "C" bool fn_27_1069E0(soSomeObj* obj) {
    return !obj->vfunc3();
}
