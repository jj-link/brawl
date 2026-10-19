#include <types.h>
#pragma force_active on

struct fn_27_1C5A28_iface {
    virtual void* pad0();
    virtual void* get(void*);
};

extern "C" void fn_27_1C5A28(fn_27_1C5A28_iface* self, u32* src, void* arg) {
    u32* result = (u32*)self->get(arg);
    *result = *src;
}
