#include <types.h>
#pragma force_active on

class soVirtualBase {
public:
    virtual void vf0(s16 a, s8 b);
};

extern "C" {
void fn_27_D40EC(soVirtualBase* self, s16 a, s8 b) {
    self->vf0(a, b);
}
}
