#include <types.h>
#pragma force_active on

class soDispatchBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(void* a, void* b, void* c);
};

struct soDispatchArg {
    u8 pad[0xc];
    u32 flags;
};

extern "C" {
void fn_27_5BC20(soDispatchBase* self, void* a, void* b, soDispatchArg* c) {
    if ((c->flags >> 6) & 1) {
        return;
    }
    self->vfunc4(a, b, c);
}
}
