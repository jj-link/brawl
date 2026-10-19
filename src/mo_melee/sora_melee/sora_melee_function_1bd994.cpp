#include <types.h>
#pragma force_active on

class fnBase {
public:
    virtual void vf0();
    virtual fnBase* vf1(int arg);
};

extern "C" {
void fn_27_1BD994(fnBase* self, u32* other, int arg) {
    u32* dst = (u32*)self->vf1(arg);
    *dst = *other;
}
}
