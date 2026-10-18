#include <types.h>
#pragma force_active on

struct soVirtualIface {
    virtual void vf0(s16 a, s8 b);
};

extern "C" {
void fn_27_D5058(soVirtualIface* self, s16 a, s8 b) {
    self->vf0(a, b);
}
}
