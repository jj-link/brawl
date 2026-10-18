#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf2(s16 a, s8 b);
};

extern "C" void fn_27_D4368(soVirtBase* self, s32 a, s32 b) {
    self->vf2((s16)a, (s8)b);
}
