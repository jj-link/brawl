#include <types.h>
#pragma force_active on

extern "C" {

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

void* __dt__14Class_8008080CFv(DtorObj* self, s32 destroy) {
    if (self != 0 && destroy > 0) {
        lbl_805A0EB8->free(self, self->type, 0x13);
    }
    return self;
}

}
