#include <types.h>
#pragma force_active on

struct fnObj27 {
    virtual void vf0();
    virtual fnObj27* vf1(void* arg);
};

extern "C" void fn_27_FA7CC(fnObj27* self, u32* src, void* arg) {
    fnObj27* p = self->vf1(arg);
    *(u32*)p = *src;
}
