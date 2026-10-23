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

void __dl__14Class_802A0DA4FPv(DtorObj* self) {
    lbl_805A0EB8->free(self, self->type, 0x1d);
}

}
