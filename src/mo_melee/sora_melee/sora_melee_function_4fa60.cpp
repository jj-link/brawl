#include <types.h>
#pragma force_active on

struct fn27Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* a, void* b, void* c);
};

struct fn27Arg {
    u32 pad[3];
    u32 flags;
};

extern "C" void fn_27_4FA60(fn27Base* self, void* a, void* b, fn27Arg* c) {
    if ((c->flags >> 8) & 1) {
        return;
    }
    self->vf4(a, b, c);
}
