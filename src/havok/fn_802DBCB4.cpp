#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf(int);
};

extern "C" {
void fn_802DBCB4(soVirtBase* p) {
    p->vf(-1);
}
}
