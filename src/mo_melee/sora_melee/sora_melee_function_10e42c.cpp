#include <types.h>
#pragma force_active on

class fn_27_Base {
public:
    virtual void vf0();
    virtual u32* vf1(void* arg);
};

extern "C" void fn_27_10E42C(fn_27_Base* self, u32* src, void* arg) {
    u32* dst = self->vf1(arg);
    *dst = *src;
}
