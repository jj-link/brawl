#include <types.h>
#pragma force_active on

class soFooAbstract {
public:
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2() = 0;
    virtual s32 vfn3() = 0;
};

extern "C" {
bool fn_27_11C6D8(soFooAbstract* p) {
    return !p->vfn3();
}
}
