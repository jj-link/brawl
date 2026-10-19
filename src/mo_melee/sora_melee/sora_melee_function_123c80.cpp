#include <types.h>
#pragma force_active on

class soWorkBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_123C80(soWorkBase* p) {
    return !p->vf3();
}
