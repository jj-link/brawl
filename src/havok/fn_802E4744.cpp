#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0(int p);
};

extern "C" {
void fn_802E4744(soVirtBase* p) {
    p->vf0(-1);
}
}
