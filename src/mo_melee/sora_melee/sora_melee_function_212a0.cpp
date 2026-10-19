#include <types.h>
#pragma force_active on

class soFn27Base {
public:
    virtual void vfunc0() = 0;
    virtual void vfunc1() = 0;
    virtual void vfunc2() = 0;
    virtual u32 vfunc3() = 0;
};

extern "C" {
bool fn_27_212A0(soFn27Base* p) {
    return !p->vfunc3();
}
}
