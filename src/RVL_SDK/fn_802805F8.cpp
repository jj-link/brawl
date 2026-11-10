#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* ptr, u16 type, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct DtorObj {
    void* vtable;
    u16 type;
};

extern "C" void* fn_802805F8(void* arg0, s32 arg1) {
    DtorObj* self = (DtorObj*)arg0;
    if (self != 0 && arg1 > 0) {
        lbl_805A0EB8->free(self, self->type, 0x16);
    }
    return self;
}
