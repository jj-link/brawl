#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0(s32 p);
};

extern "C" {
void fn_802D652C(soVirtBase* p) {
    p->vf0(-1);
}
}
