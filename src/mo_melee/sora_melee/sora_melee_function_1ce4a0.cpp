#include <types.h>
#pragma force_active on

class fn_27_Base {
public:
    virtual void vf0();
    virtual fn_27_Base* vf1(u32 arg);
};

extern "C" {
void fn_27_1CE4A0(fn_27_Base* self, u32* saved, u32 arg) {
    fn_27_Base* r = self->vf1(arg);
    *(u32*)r = *saved;
}
}
