#include <types.h>
#pragma force_active on

class stFoo {
public:
    virtual void vf0();
    virtual stFoo* vf1(u32 arg);
};

extern "C" void fn_27_2EB290(stFoo* self, u32* src, u32 arg) {
    stFoo* p = self->vf1(arg);
    *(u32*)p = *src;
}
