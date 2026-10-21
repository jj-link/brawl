#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0(int p);
    virtual void vf1();
    virtual void vf2();
};

extern "C" {
void fn_802E55F4(soVirtBase* p) {
    p->vf0(-1);
}
}
