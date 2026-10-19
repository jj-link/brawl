#include <types.h>
#pragma force_active on

class fn_27_D2FBCBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual bool vf3() = 0;
};

extern "C" {
bool fn_27_D2FBC(fn_27_D2FBCBase* p) {
    return !p->vf3();
}
}
