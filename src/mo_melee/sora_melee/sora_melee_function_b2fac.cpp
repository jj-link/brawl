#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_B16C8(void*);

struct B2FACInterface {
    virtual void* f0();
    virtual void* f1();
};

struct B2FACObject {
    u8 pad[0x18];
    B2FACInterface* interface;
};

extern "C" void fn_27_B2FAC(B2FACObject* self) {
    void* target = self->interface->f1();
    u32* work = (u32*)fn_27_B16C8(target);
    work[2] |= 0x1000;
}
