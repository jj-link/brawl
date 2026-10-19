#include <types.h>
#pragma force_active on

class fnVirtBase {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5();
};

extern "C" {
bool fn_27_106AB0(fnVirtBase* p) {
    return !p->vf5();
}
}
