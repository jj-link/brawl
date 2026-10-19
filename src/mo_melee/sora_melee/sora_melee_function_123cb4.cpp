#include <types.h>
#pragma force_active on

class soVirtualBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

extern "C" {
bool fn_27_123CB4(soVirtualBase* p) {
    return !p->vf3();
}
}
