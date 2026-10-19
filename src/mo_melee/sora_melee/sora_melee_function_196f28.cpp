#include <types.h>
#pragma force_active on

struct soGeneralWorkBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3();
};

extern "C" {
bool fn_27_196F28(soGeneralWorkBase* p) {
    return !p->vf3();
}
}
