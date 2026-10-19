#include <types.h>
#pragma force_active on

struct fn27Target {
    virtual void vf0();
    virtual u32* vf1(void* arg);
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_27_29320C(fn27Target* self, void* src, void* arg) {
    u32* p = (u32*)self->vf1(arg);
    *p = *(u32*)src;
}
