#include <types.h>
#pragma force_active on

class soVirtIface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

extern "C" bool fn_27_B12B8(soVirtIface* p) {
    return !p->vf3();
}
